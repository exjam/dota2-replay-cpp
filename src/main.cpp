#include <fstream>
#include <iostream>
#include <snappy.h>
#include <functional>
#include <sstream>
#include <map>
#include <math.h>
#include <deque>

#include "proto/ai_activity.pb.h"
#include "proto/demo.pb.h"
#include "proto/dota_commonmessages.pb.h"
#include "proto/dota_modifiers.pb.h"
#include "proto/dota_usermessages.pb.h"
#include "proto/netmessages.pb.h"
#include "proto/network_connection.pb.h"
#include "proto/networkbasetypes.pb.h"
#include "proto/usermessages.pb.h"

#include "binarystream.h"
#include "bitstream.h"

uint8_t BitStream::sBitMask[9] =
{
   0x00,
   0x01, 0x03, 0x07, 0x0f,
   0x1f, 0x3f, 0x7f, 0xff
};

std::size_t getRequiredBits(std::size_t number)
{
   return static_cast<std::size_t>(std::ceil(std::log2(number)));
}

static const auto COORD_INTEGER_BITS = 14;
static const auto COORD_FRACTIONAL_BITS = 5;
static const auto COORD_DENOMINATOR = (1 << COORD_FRACTIONAL_BITS);
static const auto COORD_RESOLUTION = (1.0f / COORD_DENOMINATOR);

static const auto COORD_INTEGER_BITS_MP = 11;
static const auto COORD_FRACTIONAL_BITS_MP_LOWPRECISION = 3;
static const auto COORD_DENOMINATOR_LOWPRECISION = (1 << COORD_FRACTIONAL_BITS_MP_LOWPRECISION);
static const auto COORD_RESOLUTION_LOWPRECISION = (1.0f / COORD_DENOMINATOR_LOWPRECISION);

static const auto NORMAL_FRACTIONAL_BITS = 11;
static const auto NORMAL_DENOMINATOR = ((1 << NORMAL_FRACTIONAL_BITS) - 1);
static const auto NORMAL_RESOLUTION = (1.0f / NORMAL_DENOMINATOR);

static const auto DT_MAX_STRING_BITS = 9;
static const auto DT_MAX_STRING_BUFFERSIZE = 1 << DT_MAX_STRING_BITS;

enum class PropertyType
{
   Int,
   Float,
   Vector,
   VectorXY,
   String,
   Array,
   DataTable,
   Int64,
   Invalid
};

enum class PropertyFlag
{
   Unsigned                = 1 <<  0,
   Coord                   = 1 <<  1,
   NoScale                 = 1 <<  2,
   RoundDown               = 1 <<  3,
   RoundUp                 = 1 <<  4,
   Normal                  = 1 <<  5,
   Exclude                 = 1 <<  6,
   Xyze                    = 1 <<  7,
   InsideArray             = 1 <<  8,
   ProxyAlways             = 1 <<  9,
   VectorElem              = 1 << 10,
   Collapsible             = 1 << 11,
   CoordMp                 = 1 << 12,
   CoordMpLowPrecision     = 1 << 13,
   CoordMpIntegral         = 1 << 14,
   CellCoord               = 1 << 15,
   CellCoordLowPrecision   = 1 << 16,
   CellCoordIntegral       = 1 << 17,
   ChangesOften            = 1 << 18,
   EncodedAgainstTickCount = 1 << 19
};

std::size_t operator&(const PropertyFlag &lhs, const PropertyFlag &rhs)
{
   return static_cast<std::size_t>(lhs) & static_cast<std::size_t>(rhs);
}

struct Property
{
   PropertyType type;
   std::string varName;
   std::string dtName;
   std::size_t numElements;
   std::size_t numBits;
   PropertyFlag flags;
   unsigned priority;
   float lowValue;
   float highValue;
   Property *arrayElementType;

   bool isExcluded()
   {
      return flags & PropertyFlag::Exclude;
   }

   bool isCollapsible()
   {
      return flags & PropertyFlag::Collapsible;
   }

   bool isChangedOften()
   {
      return flags & PropertyFlag::ChangesOften;
   }

   bool isEncodedAgainstTickCount()
   {
      return flags & PropertyFlag::EncodedAgainstTickCount;
   }

   bool isUnsigned()
   {
      return flags & PropertyFlag::Unsigned;
   }

   bool isNormal()
   {
      return flags & PropertyFlag::Normal;
   }

   bool isInsideArray()
   {
      return flags & PropertyFlag::InsideArray;
   }

   bool isArray()
   {
      return type == PropertyType::Array;
   }

   bool isDataTable()
   {
      return type == PropertyType::DataTable;
   }
};

struct Vector2f
{
   float x, y;
};

struct Vector3f
{
   float x, y, z;
};

class PropertyVariant;
using PropertyInt = int32_t;
using PropertyInt64 = int64_t;
using PropertyFloat = float;
using PropertyVector = Vector3f;
using PropertyVectorXY = Vector2f;
using PropertyString = std::string;
using PropertyArray = std::vector<PropertyVariant>;

template<typename Type>
struct get_property_type
{
   static const auto value = PropertyType::Invalid;
   static_assert(get_property_type<Type>::value != PropertyType::Invalid, "Invalid property type.");
};

template<>
struct get_property_type<PropertyInt>
{
   static const auto value = PropertyType::Int;
};

template<>
struct get_property_type<PropertyInt64>
{
   static const auto value = PropertyType::Int64;
};

template<>
struct get_property_type<PropertyFloat>
{
   static const auto value = PropertyType::Float;
};

template<>
struct get_property_type<PropertyVector>
{
   static const auto value = PropertyType::Vector;
};

template<>
struct get_property_type<PropertyVectorXY>
{
   static const auto value = PropertyType::VectorXY;
};

template<>
struct get_property_type<PropertyString>
{
   static const auto value = PropertyType::String;
};

template<>
struct get_property_type<PropertyArray>
{
   static const auto value = PropertyType::Array;
};

class PropertyVariant
{
public:
   PropertyVariant() :
      mType(PropertyType::Invalid)
   {
   }

   PropertyVariant(const PropertyVariant &other)
   {
      *this = other;
   }

   PropertyVariant(PropertyVariant &&other)
   {
      *this = std::move(other);
   }

   ~PropertyVariant()
   {
      destroy();
   }

   const PropertyType type() const
   {
      return mType;
   }

   template<typename Type>
   Type &get()
   {
      assert(mType == get_property_type<Type>::value);
      return *reinterpret_cast<const Type*>(mBuffer.data());
   }

   template<typename Type>
   const Type &get() const
   {
      assert(mType == get_property_type<Type>::value);
      return *reinterpret_cast<const Type*>(mBuffer.data());
   }

   template<typename Type>
   void set(const Type &value)
   {
      changeType(get_property_type<Type>::value);
      *reinterpret_cast<Type*>(mBuffer.data()) = value;
   }

   template<typename Type>
   void set(Type &&value)
   {
      changeType(get_property_type<Type>::value);
      *reinterpret_cast<Type*>(mBuffer.data()) = std::move(value);
   }

   PropertyVariant &operator=(PropertyVariant &&other)
   {
      mType = other.mType;
      mBuffer = std::move(other.mBuffer);
      other.mType = PropertyType::Invalid;
      return *this;
   }

   PropertyVariant &operator=(const PropertyVariant &other)
   {
      changeType(other.type());

      switch (mType) {
      case PropertyType::Int:
         set(other.get<PropertyInt>());
         break;
      case PropertyType::Int64:
         set(other.get<PropertyInt64>());
         break;
      case PropertyType::Float:
         set(other.get<PropertyFloat>());
         break;
      case PropertyType::Vector:
         set(other.get<PropertyVector>());
         break;
      case PropertyType::VectorXY:
         set(other.get<PropertyVectorXY>());
         break;
      case PropertyType::String:
         set(other.get<PropertyString>());
         break;
      case PropertyType::Array:
         set(other.get<PropertyArray>());
         break;
      }

      return *this;
   }

private:
   void changeType(PropertyType newType)
   {
      if (mType == newType) {
         return;
      }

      destroy();
      mType = newType;

      switch (mType) {
      case PropertyType::Int:
         mBuffer.resize(sizeof(PropertyInt));
         break;
      case PropertyType::Int64:
         mBuffer.resize(sizeof(PropertyInt64));
         break;
      case PropertyType::Float:
         mBuffer.resize(sizeof(PropertyFloat));
         break;
      case PropertyType::Vector:
         mBuffer.resize(sizeof(PropertyVector));
         new (mBuffer.data()) PropertyVector();
         break;
      case PropertyType::VectorXY:
         mBuffer.resize(sizeof(PropertyVectorXY));
         new (mBuffer.data()) PropertyVectorXY();
         break;
      case PropertyType::String:
         mBuffer.resize(sizeof(PropertyString));
         new (mBuffer.data()) PropertyString();
         break;
      case PropertyType::Array:
         mBuffer.resize(sizeof(PropertyArray));
         new (mBuffer.data()) PropertyArray();
         break;
      }
   }

   void destroy()
   {
      switch (mType) {
      case PropertyType::Vector:
         reinterpret_cast<PropertyVector*>(mBuffer.data())->~PropertyVector();
         break;
      case PropertyType::VectorXY:
         reinterpret_cast<PropertyVectorXY*>(mBuffer.data())->~PropertyVectorXY();
         break;
      case PropertyType::String:
         reinterpret_cast<PropertyString*>(mBuffer.data())->~PropertyString();
         break;
      case PropertyType::Array:
         reinterpret_cast<PropertyArray*>(mBuffer.data())->~PropertyArray();
         break;
      }

      mType = PropertyType::Invalid;
   }

   PropertyType mType;
   std::vector<uint8_t> mBuffer;
};

static std::ostream& operator<<(std::ostream& os, const PropertyVariant& var)
{
   switch (var.type()) {
   case PropertyType::Int:
      os << var.get<PropertyInt>();
      break;
   case PropertyType::Float:
      os << var.get<PropertyFloat>();
      break;
   case PropertyType::Vector:
   {
      auto &value = var.get<PropertyVector>();
      os << "{ x: " << value.x << ", y: " << value.y << ", z:" << value.z << " }";
      break;
   }
   case PropertyType::VectorXY:
   {
      auto &value = var.get<PropertyVectorXY>();
      os << "{ x: " << value.x << ", y: " << value.y << " }";
      break;
   }
   case PropertyType::String:
      os << var.get<PropertyString>();
      break;
   case PropertyType::Array:
   {
      auto &value = var.get<PropertyArray>();
      os << "[";
      for (auto &elem : value) {
         os << elem << ", ";
      }
      os << "]";
      break;
   }
   case PropertyType::Int64:
      os << var.get<PropertyInt64>();
      break;
   default:
      os << "{InvalidPropertyVariant}";
   }

   return os;
}

struct SendTable
{
   bool needsDecode;
   std::string name;

   std::vector<Property> properties;

   struct ExcludeProperty
   {
      ExcludeProperty(std::string table, std::string prop) :
         table(table),
         prop(prop)
      {
      }

      std::string table;
      std::string prop;
   };
};

struct ReceiveTable
{
   struct ReceiveProperty
   {
      std::string varName;
      SendTable *table;
      Property *sendProp;
   };

   std::vector<ReceiveProperty> properties;
   std::map<std::string, ReceiveProperty*> propertyMap;
};

using ReceiveTableProperties = std::vector<ReceiveTable::ReceiveProperty>;
using SendTableExclusions = std::vector<SendTable::ExcludeProperty>;

struct StringTable
{
   struct Entry
   {
      std::string strData;
      std::string userData;
   };

   std::string name;
   std::size_t maxEntries;
   std::size_t userDataSize;
   std::size_t userDataSizeBits;
   bool userDataFixedSize;
   unsigned flags;
   std::vector<Entry> entries;
   std::map<std::string, Entry*> keyMap;
};

enum class EntityPVS
{
   Preserve,
   Leave,
   Enter,
   Delete
};

struct ClassInfo
{
   unsigned id;
   std::string tableName;
   std::string networkName;
};

struct EntityState {
   std::vector<PropertyVariant> properties;
};

struct Entity
{
   std::size_t id;
   uint32_t serial;
   EntityPVS pvs;
   ClassInfo *classInfo;
   EntityState state;
};

class DemoParser
{
   std::vector<ClassInfo> mClassInfo;
   std::map<unsigned, Entity> mEntities;
   std::map<std::string, SendTable> mSendTables;
   std::map<std::string, ReceiveTable> mReceiveTables;
   std::map<std::string, StringTable> mStringTables;

public:
   bool parse(BinaryStream &in)
   {
      auto header = in.readString(8);
      header.resize(7);

      if (header.compare("PBUFDEM") != 0) {
         return 0;
      }

      // Read CDemoFileInfo
      auto offset = in.read<uint32_t>();
      auto pos = in.tell();
      in.seek(offset);
      parseMessage(in);

      // Read game messages
      in.seek(pos);

      for (unsigned i = 0; i < 1000; ++i) {
         parseMessage(in);
      }

      return true;
   }

protected:
   bool parseMessage(BinaryStream &in)
   {
      auto kind = in.readVarint<int>();
      auto tick = in.readVarint<std::size_t>();
      auto size = in.readVarint<std::size_t>();
      std::vector<uint8_t> data;

      // Decompress with Snappy if needed
      if (kind & DEM_IsCompressed) {
         auto compressed = in.readBytes(size);

         if (!snappy::GetUncompressedLength(reinterpret_cast<const char*>(compressed.data()),
                                            compressed.size(),
                                            &size)) {
            return false;
         }

         data.resize(size);

         if (!snappy::RawUncompress(reinterpret_cast<const char*>(compressed.data()),
                                    compressed.size(),
                                    reinterpret_cast<char*>(data.data()))) {
            return false;
         }
      } else {
         data = in.readBytes(size);
      }

      // Trim any flags
      kind &= ~DEM_IsCompressed;

      std::cout << "Kind: " << kind << " Tick: " << tick << " Size: " << size << std::endl;

      switch (kind) {
      case DEM_FileHeader:
         handleMessage<CDemoFileHeader>(data, &DemoParser::handleDemoFileHeader);
         break;
      case DEM_FileInfo:
         handleMessage<CDemoFileInfo>(data, &DemoParser::handleDemoFileInfo);
         break;
      case DEM_SyncTick:
         handleMessage<CDemoSyncTick>(data, &DemoParser::handleDemoSyncTick);
         break;
      case DEM_SendTables:
         handleMessage<CDemoSendTables>(data, &DemoParser::handleDemoSendTables);
         break;
      case DEM_ClassInfo:
         handleMessage<CDemoClassInfo>(data, &DemoParser::handleDemoClassInfo);
         break;
      case DEM_Packet:
      case DEM_SignonPacket:
         handleMessage<CDemoPacket>(data, &DemoParser::handleDemoPacket);
         break;
      case DEM_FullPacket:
         handleMessage<CDemoFullPacket>(data, &DemoParser::handleDemoFullPacket);
         break;
      case DEM_Error:
      case DEM_Stop:
      case DEM_StringTables:
      case DEM_ConsoleCmd:
      case DEM_CustomData:
      case DEM_CustomDataCallbacks:
      case DEM_UserCmd:
      case DEM_SaveGame:
      default:
         std::cout << "Unhandled message type " << kind << std::endl;
         return false;
      }

      return true;
   }

   bool parseSubMessage(BinaryStream &in)
   {
      while (!in.eof()) {
         auto kind = in.readVarint<int>();
         auto size = in.readVarint<std::size_t>();
         auto data = in.readBytes(size);

         std::cout << "Kind: " << kind << " Size: " << size << std::endl;

         switch (kind) {
         case svc_SendTable:
            handleMessage<CSVCMsg_SendTable>(data, &DemoParser::handleSendTable);
            break;
         case svc_CreateStringTable:
            handleMessage<CSVCMsg_CreateStringTable>(data, &DemoParser::handleCreateStringTable);
            break;
         case svc_UpdateStringTable:
            handleMessage<CSVCMsg_UpdateStringTable>(data, &DemoParser::handleUpdateStringTable);
            break;
         case svc_UserMessage:
            handleMessage<CSVCMsg_UserMessage>(data, &DemoParser::parseUserMessage);
            break;
         case svc_ServerInfo:
            handleMessage<CSVCMsg_ServerInfo>(data, &DemoParser::handleServerInfo);
            break;
         case svc_PacketEntities:
            handleMessage<CSVCMsg_PacketEntities>(data, &DemoParser::parsePacketEntities);
            break;
         // networkbasetypes.pb.h
         case net_NOP:
         case net_Disconnect:
         case net_File:
         case net_SplitScreenUser:
         case net_Tick:
         case net_StringCmd:
         case net_SetConVar:
         case net_SignonState:
         // netmessages.pb.h
         case svc_ClassInfo:
         case svc_SetPause:
         case svc_VoiceInit:
         case svc_VoiceData:
         case svc_Print:
         case svc_Sounds:
         case svc_SetView:
         case svc_FixAngle:
         case svc_CrosshairAngle:
         case svc_BSPDecal:
         case svc_SplitScreen:
         case svc_EntityMessage:
         case svc_GameEvent:
         case svc_TempEntities:
         case svc_Prefetch:
         case svc_Menu:
         case svc_GameEventList:
         case svc_GetCvarValue:
         case svc_PacketReliable:
         case svc_FullFrameSplit:
         default:
            std::cout << "Unhandled sub-message type " << kind << std::endl;
         };
      }

      return true;
   }

   bool parseUserMessage(const CSVCMsg_UserMessage &message)
   {
      auto kind = message.msg_type();
      auto data = message.msg_data();

      std::cout << "Kind: " << kind << std::endl;

      switch (kind) {
      // usermessages.pb.h
      case UM_AchievementEvent:
      case UM_CloseCaption:
      case UM_CloseCaptionDirect:
      case UM_CurrentTimescale:
      case UM_DesiredTimescale:
      case UM_Fade:
      case UM_GameTitle:
      case UM_Geiger:
      case UM_HintText:
      case UM_HudMsg:
      case UM_HudText:
      case UM_KeyHintText:
      case UM_MessageText:
      case UM_RequestState:
      case UM_ResetHUD:
      case UM_Rumble:
      case UM_SayText:
      case UM_SayText2:
      case UM_SayTextChannel:
      case UM_Shake:
      case UM_ShakeDir:
      case UM_StatsCrawlMsg:
      case UM_StatsSkipState:
      case UM_TextMsg:
      case UM_Tilt:
      case UM_Train:
      case UM_VGUIMenu:
      case UM_VoiceMask:
      case UM_VoiceSubtitle:
      case UM_SendAudio:
      case UM_CameraTransition:
      // dota_usermessages.pb.h
      case DOTA_UM_AddUnitToSelection:
      case DOTA_UM_AIDebugLine:
      case DOTA_UM_ChatEvent:
      case DOTA_UM_CombatHeroPositions:
      case DOTA_UM_CombatLogData:
      case DOTA_UM_CombatLogShowDeath:
      case DOTA_UM_CreateLinearProjectile:
      case DOTA_UM_DestroyLinearProjectile:
      case DOTA_UM_DodgeTrackingProjectiles:
      case DOTA_UM_GlobalLightColor:
      case DOTA_UM_GlobalLightDirection:
      case DOTA_UM_InvalidCommand:
      case DOTA_UM_LocationPing:
      case DOTA_UM_MapLine:
      case DOTA_UM_MiniKillCamInfo:
      case DOTA_UM_MinimapDebugPoint:
      case DOTA_UM_MinimapEvent:
      case DOTA_UM_NevermoreRequiem:
      case DOTA_UM_OverheadEvent:
      case DOTA_UM_SetNextAutobuyItem:
      case DOTA_UM_SharedCooldown:
      case DOTA_UM_SpectatorPlayerClick:
      case DOTA_UM_TutorialTipInfo:
      case DOTA_UM_UnitEvent:
      case DOTA_UM_ParticleManager:
      case DOTA_UM_BotChat:
      case DOTA_UM_HudError:
      case DOTA_UM_ItemPurchased:
      case DOTA_UM_Ping:
      case DOTA_UM_ItemFound:
      case DOTA_UM_CharacterSpeakConcept:
      case DOTA_UM_SwapVerify:
      case DOTA_UM_WorldLine:
      case DOTA_UM_TournamentDrop:
      case DOTA_UM_ItemAlert:
      case DOTA_UM_HalloweenDrops:
      case DOTA_UM_ChatWheel:
      case DOTA_UM_ReceivedXmasGift:
      case DOTA_UM_UpdateSharedContent:
      case DOTA_UM_TutorialRequestExp:
      case DOTA_UM_TutorialPingMinimap:
      case DOTA_UM_GamerulesStateChanged:
      case DOTA_UM_ShowSurvey:
      case DOTA_UM_TutorialFade:
      case DOTA_UM_AddQuestLogEntry:
      case DOTA_UM_SendStatPopup:
      case DOTA_UM_TutorialFinish:
      case DOTA_UM_SendRoshanPopup:
      case DOTA_UM_SendGenericToolTip:
      case DOTA_UM_SendFinalGold:
      case DOTA_UM_CustomMsg:
      case DOTA_UM_CoachHUDPing:
      case DOTA_UM_ClientLoadGridNav:
      case DOTA_UM_AbilityPing:
      case DOTA_UM_ShowGenericPopup:
      case DOTA_UM_VoteStart:
      case DOTA_UM_VoteUpdate:
      case DOTA_UM_VoteEnd:
      case DOTA_UM_BoosterState:
      case DOTA_UM_WillPurchaseAlert:
      case DOTA_UM_TutorialMinimapPosition:
      case DOTA_UM_PlayerMMR:
      case DOTA_UM_AbilitySteal:
      case DOTA_UM_CourierKilledAlert:
      case DOTA_UM_EnemyItemAlert:
      case DOTA_UM_StatsMatchDetails:
      case DOTA_UM_MiniTaunt:
      case DOTA_UM_BuyBackStateAlert:
      case DOTA_UM_QuickBuyAlert:
      case DOTA_UM_StatsHeroDetails:
      case DOTA_UM_PredictionResult:
      default:
         std::cout << "Unhandled user-message type " << kind << std::endl;
         return false;
      }

      return true;
   }

   template<typename Type, typename Handler>
   bool handleMessage(std::vector<uint8_t> &raw, Handler handler)
   {
      Type message;

      if (!message.ParseFromArray(raw.data(), raw.size())) {
         return false;
      }

      return (this->*handler)(message);
   }

   bool handleDemoClassInfo(const CDemoClassInfo &info)
   {
      for (int i = 0; i < info.classes_size(); ++i) {
         auto cls = info.classes(i);
         auto info = ClassInfo {};
         info.id = cls.class_id();
         info.tableName = cls.table_name();
         info.networkName = cls.network_name();
         mClassInfo[info.id] = info;
      }

      return true;
   }

   bool handleDemoFileInfo(const CDemoFileInfo &info)
   {
      auto game = info.game_info();
      auto dota = game.dota();

      for (int i = 0; i < dota.player_info_size(); ++i) {
         auto player = dota.player_info(i);
         auto name = player.player_name();
         auto hero = player.hero_name();
         std::cout << "Player: " << name << " Hero: " << hero << std::endl;
      }

      return true;
   }

   class SendTableFlattenException : public std::exception
   {
   public:
      SendTableFlattenException(std::string what)
      {
         mWhat = "Error flattening SendTable. " + what;
      }

      virtual const char* what() const throw(){
        return mWhat.c_str();
      }

   private:
      std::string mWhat;
   };

   bool sendTableGetExclusions(SendTable &table, SendTableExclusions &exclusions)
   {
      for (auto &&prop : table.properties) {
         if (prop.isExcluded()) {
            exclusions.emplace_back(prop.dtName, prop.varName);
         } else if (prop.isDataTable()) {
            auto itr = mSendTables.find(prop.dtName);

            if (itr == mSendTables.end()) {
               throw SendTableFlattenException("Could not find base class " + prop.dtName);
            }

            sendTableGetExclusions(itr->second, exclusions);
         }
      }

      return true;
   }

   bool isExcluded(SendTableExclusions &exclusions, std::string table, std::string name)
   {
      for (auto &&exclusion : exclusions) {
         if (exclusion.table.compare(table) == 0 && exclusion.prop.compare(name) == 0) {
            return true;
         }
      }

      return false;
   }

   bool sendTableBuildHeirarchyProperties(SendTable &sendTable, ReceiveTable &recvTable, SendTableExclusions &exclusions, ReceiveTableProperties &recvProps, std::string path)
   {
      for (auto &&sendProp : sendTable.properties) {
         if (sendProp.isExcluded() || sendProp.isInsideArray()) {
            continue;
         }

         if (isExcluded(exclusions, sendTable.name, sendProp.varName)) {
            continue;
         }

         if (sendProp.isDataTable()) {
            if (sendProp.isCollapsible()) {
               sendTableBuildHeirarchyProperties(mSendTables[sendProp.dtName], recvTable, exclusions, recvProps, path);
            } else {
               path.append(sendProp.varName);
               path.push_back('.');
               sendTableBuildHeirarchy(mSendTables[sendProp.dtName], recvTable, exclusions, path);
               path.resize(path.size() - 1 - sendProp.varName.size());
            }
         } else {
            recvProps.push_back({ path + sendProp.varName, &sendTable, &sendProp });
         }
      }

      return true;
   }

   bool sendTableBuildHeirarchy(SendTable &sendTable, ReceiveTable &recvTable, SendTableExclusions &exclusions, std::string path)
   {
      auto properties = ReceiveTableProperties {};
      sendTableBuildHeirarchyProperties(sendTable, recvTable, exclusions, properties, path);
      recvTable.properties.insert(recvTable.properties.end(), properties.begin(), properties.end());
      return true;
   }

   bool recvTableSortProperties(ReceiveTableProperties &properties)
   {
      auto priorities = std::set<unsigned> { 64 };
      auto offset = std::size_t { 0 };

      for (auto &&prop : properties) {
         priorities.insert(prop.sendProp->priority);
      }

      for (auto priority : priorities) {
         auto hole = offset;
         auto cursor = offset;

         while (cursor < properties.size()) {
            auto &prop = properties[cursor];
            auto sendProp = prop.sendProp;

            if (sendProp->priority == priority || (sendProp->isChangedOften() && priority == 64)) {
               std::iter_swap(properties.begin() + cursor, properties.begin() + hole);
               hole++;
               offset++;
            }

            cursor++;
         }
      }

      return true;
   }

   bool setupFlatPropertyArray(SendTable &sendTable)
   {
      auto &recvTable = mReceiveTables[sendTable.name];
      auto exclusions = SendTableExclusions {};

      if (!sendTableGetExclusions(sendTable, exclusions)) {
         return false;
      }

      if (!sendTableBuildHeirarchy(sendTable, recvTable, exclusions, {})) {
         return false;
      }

      if (!recvTableSortProperties(recvTable.properties)) {
         return false;
      }

      for (auto &&prop : recvTable.properties) {
         recvTable.propertyMap[prop.varName] = &prop;
      }

      return true;
   }

   bool handleDemoSyncTick(const CDemoSyncTick &/*msg*/)
   {
      for (auto &&kvpair : mSendTables) {
         auto &table = kvpair.second;

         if (table.needsDecode) {
            setupFlatPropertyArray(table);
            table.needsDecode = false;
         }
      }

      return true;
   }

   bool handleDemoFileHeader(const CDemoFileHeader &header)
   {
      return true;
   }

   bool handleStringTables(const CDemoStringTables &tables)
   {
      return true;
   }

   bool handleSendTable(const CSVCMsg_SendTable &msg)
   {
      auto name = msg.net_table_name();
      auto itr = mSendTables.find(name);

      if (itr != mSendTables.end()) {
         // Update?
         assert(0);
      } else {
         SendTable &table = mSendTables[name];
         table.name = name;
         table.needsDecode = msg.needs_decoder();
         table.properties.resize(msg.props_size());

         for (int i = 0; i < msg.props_size(); ++i) {
            auto &sp = table.properties[i];
            auto &prop = msg.props(i);

            sp.dtName = prop.dt_name();
            sp.varName = prop.var_name();
            sp.priority = prop.priority();
            sp.numBits = prop.num_bits();
            sp.numElements = prop.num_elements();
            sp.lowValue = prop.low_value();
            sp.highValue = prop.high_value();
            sp.type = static_cast<PropertyType>(prop.type());
            sp.flags = static_cast<PropertyFlag>(prop.flags());

            if (sp.isArray()) {
               assert(i > 0);
               sp.arrayElementType = &table.properties[i - 1];
            } else {
               sp.arrayElementType = nullptr;
            }
         }
      }

      return true;
   }

   class ParseStringTableException : public std::exception
   {
   public:
      ParseStringTableException(std::string what)
      {
         mWhat = "Error parsing StringTable. " + what;
      }

      virtual const char* what() const throw(){
        return mWhat.c_str();
      }

   private:
      std::string mWhat;
   };

   using EntityPropList = std::vector<std::size_t>;

   EntityPropList parseEntityPropList(BitStream &in)
   {
      auto propList = EntityPropList { };
      auto offset = 0;
      auto index = -1;

      while (true) {
         if (in.readBit()) {
            ++index;
         } else {
            offset = in.readVarInt();

            if (offset == 0x3fff) {
               break;
            }

            index += offset + 1;
         }

         propList.push_back(static_cast<std::size_t>(index));
      }

      return propList;
   }

   PropertyInt parsePropertyInt(BitStream &in, Property &prop)
   {
      auto value = PropertyInt { 0 };

      if (prop.isEncodedAgainstTickCount()) {
         value = in.readVarInt();
      } else if (prop.isUnsigned()) {
         value = in.read<uint32_t>(prop.numBits);
      } else {
         value = in.read<int32_t>(prop.numBits);
      }

      return value;
   }

   PropertyInt64 parsePropertyInt64(BitStream &in, Property &prop)
   {
      auto value = PropertyInt64 { 0 };

      if (prop.isEncodedAgainstTickCount()) {
         return in.readVarInt();
      }

      auto sign = 0;
      auto bits = prop.numBits;

      if (!prop.isUnsigned()) {
         sign = in.readBit();
         bits--;
      }

      value = in.read<uint64_t>(bits);
      return sign ? -value : value;
   }

   PropertyFloat parsePropertyFloatCoord(BitStream &in, Property &prop)
   {
      auto value = PropertyFloat { 0 };
      auto hasIntegral = in.readBit();
      auto hasFractional = in.readBit();

      if (!hasIntegral && !hasFractional) {
         return 0.0f;
      }

      auto sign = in.readBit();
      auto integral = 0.0f;
      auto fractional = 0.0f;

      if (hasIntegral) {
         integral = static_cast<float>(in.read<uint32_t>(COORD_INTEGER_BITS) + 1);
      }

      if (hasFractional) {
         fractional = static_cast<float>(in.read<uint32_t>(COORD_FRACTIONAL_BITS));
      }

      value = integral + fractional * COORD_RESOLUTION;
      return sign ? -value : value;
   }

   PropertyFloat parsePropertyFloatCoordMp(BitStream &in, Property &prop)
   {
      auto value = PropertyFloat { 0 };
      auto inBounds = !!in.readBit();
      auto hasInt = in.readBit();
      auto sign = in.readBit();
      auto integral = 0.0f;

      if (hasInt) {
        if (inBounds) {
          integral = static_cast<PropertyFloat>(in.read<uint32_t>(COORD_INTEGER_BITS_MP) + 1);
        } else {
          integral = static_cast<PropertyFloat>(in.read<uint32_t>(COORD_INTEGER_BITS) + 1);
        }
      }

      auto fractional = static_cast<PropertyFloat>(in.read<uint32_t>(COORD_FRACTIONAL_BITS));
      value = integral + (fractional * COORD_RESOLUTION);
      return sign ? -value : value;
   }

   PropertyFloat parsePropertyFloatCoordMpIntegral(BitStream &in, Property &prop)
   {
      auto value = PropertyFloat { 0 };
      auto sign = 0;
      auto inBounds = !!in.readBit();

      if (in.readBit()) {
        sign = in.readBit();

        if (inBounds) {
          value = static_cast<PropertyFloat>(in.read<uint32_t>(COORD_INTEGER_BITS_MP) + 1);
        } else {
          value = static_cast<PropertyFloat>(in.read<uint32_t>(COORD_INTEGER_BITS) + 1);
        }
      }

      return sign ? -value : value;
   }

   PropertyFloat parsePropertyFloatCoordMpLowPrecision(BitStream &in, Property &prop)
   {
      auto value = PropertyFloat { 0 };
      auto inBounds = !!in.readBit();
      auto hasInt = in.readBit();
      auto sign = in.readBit();
      auto integral = 0.0f;

      if (hasInt) {
        if (inBounds) {
          integral = static_cast<float>(in.read<uint32_t>(COORD_INTEGER_BITS_MP) + 1);
        } else {
          integral = static_cast<float>(in.read<uint32_t>(COORD_INTEGER_BITS) + 1);
        }
      }

      auto fractional = static_cast<float>(in.read<uint32_t>(COORD_FRACTIONAL_BITS_MP_LOWPRECISION));
      value = integral + (fractional * COORD_RESOLUTION_LOWPRECISION);
      return sign ? -value : value;
   }

   PropertyFloat parsePropertyFloatNoScale(BitStream &in, Property &prop)
   {
      auto value = PropertyFloat { 0 };
      value = in.read<float>(32);
      return value;
   }

   PropertyFloat parsePropertyFloatNormal(BitStream &in, Property &prop)
   {
      auto value = PropertyFloat { 0 };
      auto sign = in.readBit();
      value = static_cast<PropertyFloat>(in.read<uint32_t>(NORMAL_FRACTIONAL_BITS));
      value *= NORMAL_RESOLUTION;
      return sign ? -value : value;
   }

   PropertyFloat parsePropertyFloatCellCoord(BitStream &in, Property &prop)
   {
      auto value = PropertyFloat { 0 };
      value = static_cast<PropertyFloat>(in.read<uint32_t>(prop.numBits));
      value += COORD_RESOLUTION * static_cast<PropertyFloat>(in.read<uint32_t>(COORD_FRACTIONAL_BITS));
      return value;
   }

   PropertyFloat parsePropertyFloatCellCoordIntegral(BitStream &in, Property &prop)
   {
      auto value = PropertyFloat { 0 };
      value = static_cast<PropertyFloat>(in.read<uint32_t>(prop.numBits));
      return value;
   }

   PropertyFloat parsePropertyFloatDefault(BitStream &in, Property &prop)
   {
      auto value = PropertyFloat { 0 };
      value = static_cast<PropertyFloat>(in.read<uint32_t>(prop.numBits));
      value /= (1 << prop.numBits) - 1;
      return value * (prop.highValue - prop.lowValue) + prop.lowValue;
   }

   PropertyFloat parsePropertyFloat(BitStream &in, Property &prop)
   {
      auto value = PropertyFloat { 0 };

      if (prop.flags & PropertyFlag::Coord) {
         value = parsePropertyFloatCoord(in, prop);
      } else if (prop.flags & PropertyFlag::CoordMp) {
         value = parsePropertyFloatCoordMp(in, prop);
      } else if (prop.flags & PropertyFlag::CoordMpIntegral) {
         value = parsePropertyFloatCoordMpIntegral(in, prop);
      } else if (prop.flags & PropertyFlag::CoordMpLowPrecision) {
         value = parsePropertyFloatCoordMpLowPrecision(in, prop);
      } else if (prop.flags & PropertyFlag::NoScale) {
         value = parsePropertyFloatNoScale(in, prop);
      } else if (prop.flags & PropertyFlag::Normal) {
         value = parsePropertyFloatNormal(in, prop);
      } else if (prop.flags & PropertyFlag::CellCoord) {
         value = parsePropertyFloatCellCoord(in, prop);
      } else if (prop.flags & PropertyFlag::CellCoordIntegral) {
         value = parsePropertyFloatCellCoordIntegral(in, prop);
      } else {
         value = parsePropertyFloatDefault(in, prop);
      }

      return value;
   }

   PropertyVector parsePropertyVector(BitStream &in, Property &prop)
   {
      auto value = PropertyVector { };
      value.x = parsePropertyFloat(in, prop);
      value.y = parsePropertyFloat(in, prop);

      if (prop.isNormal()) {
         auto d = value.x * value.x + value.y * value.y;
         value.z = (d >= 1.0) ? 0.0 : std::sqrt(1.0 - d);

         if (in.readBit()) {
            value.z *= -1;
         }
      } else {
         value.z = parsePropertyFloat(in, prop);
      }

      return value;
   }

   PropertyVectorXY parsePropertyVectorXY(BitStream &in, Property &prop)
   {
      auto value = PropertyVectorXY { };
      value.x = parsePropertyFloat(in, prop);
      value.y = parsePropertyFloat(in, prop);
      return value;
   }

   PropertyString parsePropertyString(BitStream &in, Property &prop)
   {
      auto value = PropertyString { };
      auto length = in.read<std::size_t>(DT_MAX_STRING_BITS);

      if (length >= DT_MAX_STRING_BUFFERSIZE) {
         length = DT_MAX_STRING_BUFFERSIZE - 1;
      }

      value = in.readStringLength(length);
      return value;
   }

   PropertyArray parsePropertyArray(BitStream &in, Property &prop)
   {
      auto value = PropertyArray { };
      auto numBits = getRequiredBits(prop.numElements);
      auto count = in.read<std::size_t>(numBits);
      auto type = prop.arrayElementType;
      assert(type);

      value.resize(count);

      for (std::size_t i = 0; i < count; ++i) {
         auto &variant = value[i];
         parsePropertyValue(in, *type, variant);
      }

      return value;
   }

   bool parsePropertyValue(BitStream &in, Property &prop, PropertyVariant &variant)
   {
      switch (prop.type) {
      case PropertyType::Int:
         variant.set(parsePropertyInt(in, prop));
         break;
      case PropertyType::Int64:
         variant.set(parsePropertyInt64(in, prop));
         break;
      case PropertyType::Float:
         variant.set(parsePropertyFloat(in, prop));
         break;
      case PropertyType::Vector:
         variant.set(parsePropertyVector(in, prop));
         break;
      case PropertyType::VectorXY:
         variant.set(parsePropertyVectorXY(in, prop));
         break;
      case PropertyType::String:
         variant.set(parsePropertyString(in, prop));
         break;
      case PropertyType::Array:
         variant.set(parsePropertyArray(in, prop));
         break;
      default:
         return false;
      }

      return true;
   }

   bool parsePacketEntities(const CSVCMsg_PacketEntities &msg)
   {
      auto stream = std::istringstream { msg.entity_data() };
      auto bin = BinaryStream { stream };
      auto in = BitStream { bin };
      auto classBits = getRequiredBits(mServerInfo.maxClasses);
      auto index = -1;

      for (int i = 0; i < msg.updated_entries(); ++i) {
         // Read index
         auto indexOffset = in.read<std::size_t>(6);
         auto indexExtra = (indexOffset >> 4) & 0x3;

         switch (indexExtra) {
         case 0x1:
            indexOffset = (indexOffset & 0x0f) | (in.read<std::size_t>(4) << 4);
            break;
         case 0x2:
            indexOffset = (indexOffset & 0x0f) | (in.read<std::size_t>(8) << 4);
            break;
         case 0x3:
            indexOffset = (indexOffset & 0x0f) | (in.read<std::size_t>(28) << 4);
            break;
         }

         index += indexOffset + 1;

         switch(in.read<unsigned>(2)) {
         case EntityPVS::Preserve:
         {
            std::cout << "Preserve Entity " << index << std::endl;
            assert(mEntities.find(index) != mEntities.end());

            Entity &entity = mEntities[index];
            entity.pvs = EntityPVS::Preserve;

            auto &recvTable = mReceiveTables[entity.classInfo->tableName];
            auto entityPropList = parseEntityPropList(in);

            //std::cout << "Entity Properties" << std::endl;
            for (auto propID : entityPropList) {
               auto &prop = recvTable.properties[propID];
               auto &value = entity.state.properties[propID];
               parsePropertyValue(in, *prop.sendProp, value);
               //std::cout << prop.varName << " = " << value << std::endl;
            }
            break;
         }
         break;
         case EntityPVS::Leave:
         {
            std::cout << "Leave Entity " << index << std::endl;
            assert(mEntities.find(index) != mEntities.end());

            Entity &entity = mEntities[index];
            entity.pvs = EntityPVS::Leave;
            break;
         }
         case EntityPVS::Enter:
         {
            std::cout << "Enter Entity " << index << std::endl;

            auto classId = in.read<std::size_t>(classBits);
            auto classIdStr = std::to_string(classId);
            auto serial = in.read<unsigned>(10);
            auto &classInfo = mClassInfo[classId];
            auto &recvTable = mReceiveTables[classInfo.tableName];
            auto &baselineTable = mStringTables["instancebaseline"];

            auto baselineItr = baselineTable.keyMap.find(classIdStr);
            assert(baselineItr != baselineTable.keyMap.end());

            auto baseline = baselineItr->second;
            auto baselineStream = std::istringstream { baseline->userData };
            auto baselineBinary = BinaryStream { baselineStream };
            auto baselineIn = BitStream { baselineBinary };

            auto isNew = (mEntities.find(index) == mEntities.end());
            auto &entity = mEntities[index];

            if (!isNew && entity.serial != serial) {
               entity = Entity { };
            }

            entity.id = index;
            entity.serial = serial;
            entity.classInfo = &classInfo;
            entity.pvs = EntityPVS::Enter;
            entity.state.properties.resize(recvTable.properties.size());

            //std::cout << "Baseline Properties" << std::endl;
            auto baselinePropList = parseEntityPropList(baselineIn);

            for (auto propID : baselinePropList) {
               auto &prop = recvTable.properties[propID];
               auto &value = entity.state.properties[propID];
               parsePropertyValue(baselineIn, *prop.sendProp, value);
               //std::cout << (baselineIn.mOffset - 8 + 8 * (unsigned)baselineStream.tellg()) << " " << prop.varName << " = " << value << std::endl;
            }

            //std::cout << "Entity Properties" << std::endl;
            auto entityPropList = parseEntityPropList(in);

            for (auto propID : entityPropList) {
               auto &prop = recvTable.properties[propID];
               auto &value = entity.state.properties[propID];
               parsePropertyValue(in, *prop.sendProp, value);
               //std::cout << (baselineIn.mOffset - 8 + 8 * (unsigned)stream.tellg()) << " " << prop.varName << " = " << value << std::endl;
            }
            break;
         }
         case EntityPVS::Delete:
            std::cout << "Delete Entity " << index << std::endl;
            assert(mEntities.find(index) != mEntities.end());
            mEntities.erase(index);
            break;
         }
      }

      return true;
   }

   bool parseStringTable(StringTable &table, BitStream &in, std::size_t entries)
   {
      static const unsigned STRING_HISTORY_SIZE = 32;
      auto indexBits = getRequiredBits(table.maxEntries);
      auto history = std::deque<std::string> {};
      auto index = -1;
      auto format = in.readBit();

      for (std::size_t i = 0; i < entries; ++i) {
         // Read index
         if (in.readBit()) {
            index++;
         } else {
            index = in.read<uint32_t>(indexBits);
         }

         auto &entry = table.entries[index];

         // Read str_data
         if (in.readBit()) {
            if (format && in.readBit()) {
               throw ParseStringTableException("Unsupported format flags.");
            }

            if (in.readBit()) {
               auto strIndex = in.read<std::size_t>(5);
               auto strLength = in.read<std::size_t>(5);
               entry.strData = history[strIndex].substr(0, strLength);
               entry.strData += in.readNullTerminatedString();
            } else {
               entry.strData = in.readNullTerminatedString();
            }

            if (history.size() >= STRING_HISTORY_SIZE) {
               history.pop_front();
            }

            history.emplace_back(entry.strData);
         }

         // Read user_data
         if (in.readBit()) {
            auto length = table.userDataSizeBits;

            if (!table.userDataFixedSize) {
               length = in.read<std::size_t>(14) * 8;
            }

            entry.userData = in.readBits(length);
         }

         if (entry.strData.size() && entry.userData.size()) {
            table.keyMap[entry.strData] = &entry;
         }
      }

      return true;
   }

   class CreateStringTableException : public std::exception
   {
   public:
      CreateStringTableException(std::string what)
      {
         mWhat = "Error creating StringTable. " + what;
      }

      virtual const char* what() const throw(){
        return mWhat.c_str();
      }

   private:
      std::string mWhat;
   };

   bool handleCreateStringTable(const CSVCMsg_CreateStringTable &msg)
   {
      auto name = msg.name();
      auto itr = mStringTables.find(name);

      if (itr != mStringTables.end()) {
         throw CreateStringTableException("Table already exists.");
      }

      auto &table = mStringTables[name];
      table.name = name;
      table.maxEntries = msg.max_entries();
      table.userDataFixedSize = msg.user_data_fixed_size();
      table.userDataSize = msg.user_data_size();
      table.userDataSizeBits = msg.user_data_size_bits();
      table.flags = msg.flags();
      table.entries.resize(table.maxEntries);

      auto stream = std::istringstream { msg.string_data() };
      auto binary = BinaryStream { stream };
      auto in = BitStream { binary };
      return parseStringTable(table, in, msg.num_entries());
   }

   bool handleUpdateStringTable(const CSVCMsg_UpdateStringTable &table)
   {
      return true;
   }

   struct ServerInfo
   {
      std::size_t maxClasses;
   };

   ServerInfo mServerInfo;

   bool handleServerInfo(const CSVCMsg_ServerInfo &info)
   {
      mServerInfo.maxClasses = info.max_classes();
      mClassInfo.resize(mServerInfo.maxClasses);
      return true;
   }

   bool handleDemoPacket(const CDemoPacket &packet)
   {
      auto stream = std::istringstream { packet.data() };
      auto in = BinaryStream { stream };
      return parseSubMessage(in);
   }

   bool handleDemoFullPacket(const CDemoFullPacket &packet)
   {
      bool success = true;
      success &= handleDemoPacket(packet.packet());
      success &= handleStringTables(packet.string_table());
      return success;
   }

   bool handleDemoSendTables(const CDemoSendTables &packet)
   {
      auto stream = std::istringstream { packet.data() };
      auto in = BinaryStream { stream };
      return parseSubMessage(in);
   }

private:
};

int main()
{
   auto file = std::ifstream { "test.dem", std::ifstream::binary };
   auto in = BinaryStream { file };
   auto demo = DemoParser {};
   demo.parse(in);
   return 0;
}
