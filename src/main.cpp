#include <fstream>
#include <iostream>
#include <snappy.h>
#include <functional>
#include <sstream>
#include <map>

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
unsigned char BitStream::sBitMask[9] = {
   0x00,
   0x01, 0x03, 0x07, 0x0f,
   0x1f, 0x3f, 0x7f, 0xff
};

using namespace std;

class DemoParser {
public:
   bool parse(BinaryStream &in) {
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

      for (unsigned i = 0; i < 100; ++i) {
         parseMessage(in);
      }

      return true;
   }

protected:
   bool parseMessage(BinaryStream &in) {
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
      case DEM_SendTables:
         handleMessage<CDemoSendTables>(data, &DemoParser::handleDemoSendTables);
         break;
      case DEM_Error:
      case DEM_Stop:
      case DEM_SyncTick:
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

   bool parseSubMessage(BinaryStream &in) {
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
      case svc_ServerInfo:
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
      case svc_PacketEntities:
      case svc_TempEntities:
      case svc_Prefetch:
      case svc_Menu:
      case svc_GameEventList:
      case svc_GetCvarValue:
      case svc_PacketReliable:
      case svc_FullFrameSplit:
      default:
         std::cout << "Unhandled sub-message type " << kind << std::endl;
         return false;
      };

      return true;
   }

   bool parseUserMessage(const CSVCMsg_UserMessage &message) {
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
   bool handleMessage(std::vector<uint8_t> &raw, Handler handler) {
      Type message;

      if (!message.ParseFromArray(raw.data(), raw.size())) {
         return false;
      }

      return (this->*handler)(message);
   }

   struct ClassInfo {
      int32_t id;
      std::string table_name;
      std::string network_name;
   };

   std::vector<ClassInfo> mClassInfo;

   bool handleDemoClassInfo(const CDemoClassInfo &info) {
      for (int i = 0; i < info.classes_size(); ++i) {
         auto cls = info.classes(i);
         mClassInfo.push_back({ cls.class_id(), cls.table_name(), cls.network_name() });
      }

      return true;
   }

   bool handleDemoFileInfo(const CDemoFileInfo &info) {
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

   bool handleDemoFileHeader(const CDemoFileHeader &header) {
      return true;
   }

   bool handleStringTables(const CDemoStringTables &tables) {
      return true;
   }

   struct SendTable {
      bool needs_decode;
      std::string name;

      struct Property {
         int32_t type;
         std::string var_name;
         int32_t flags;
         int32_t priority;
         std::string dt_name;
         int32_t num_elements;
         float low_value;
         float high_value;
         int32_t num_bits;
      };

      std::vector<Property> properties;
   };

   std::map<std::string, SendTable> mSendTables;

   bool handleSendTable(const CSVCMsg_SendTable &msg) {
      auto name = msg.net_table_name();
      auto itr = mSendTables.find(name);

      if (itr != mSendTables.end()) {
         // Update?
         assert(0);
      } else {
         SendTable &table = mSendTables[name];
         table.name = name;
         table.needs_decode = msg.needs_decoder();
         table.properties.resize(msg.props_size());

         for (int i = 0; i < msg.props_size(); ++i) {
            auto &sp = table.properties[i];
            auto &prop = msg.props(i);

            sp.type = prop.type();
            sp.var_name = prop.var_name();
            sp.flags = prop.flags();
            sp.priority = prop.priority();
            sp.dt_name = prop.dt_name();
            sp.num_elements = prop.num_elements();
            sp.low_value = prop.low_value();
            sp.high_value = prop.high_value();
            sp.num_bits = prop.num_bits();
         }
      }

      return true;
   }

   struct StringTable {
      std::string name;
      int32_t max_entries;
      int32_t num_entries;
      bool user_data_fixed_size;
      int32_t user_data_size;
      int32_t user_data_size_bits;
      int32_t flags;
   };

   std::map<std::string, StringTable> mStringTables;

   bool parseStringTable(StringTable &table, BitStream &in) {
      in.readBit(); // Unknown
      return false;
   }

   bool handleCreateStringTable(const CSVCMsg_CreateStringTable &msg) {
      auto name = msg.name();
      auto itr = mStringTables.find(name);

      if (itr != mStringTables.end()) {
         // TODO: Throw error
         return false;
      }

      StringTable &table = mStringTables[name];
      table.name = name;
      table.max_entries = msg.max_entries();
      table.num_entries = msg.num_entries();
      table.user_data_fixed_size = msg.user_data_fixed_size();
      table.user_data_size = msg.user_data_size();
      table.user_data_size_bits = msg.user_data_size_bits();
      table.flags = msg.flags();

      auto stream = std::istringstream { msg.string_data() };
      auto binary = BinaryStream { stream };
      auto in = BitStream { binary };
      parseStringTable(table, in);
      return true;
   }

   bool handleUpdateStringTable(const CSVCMsg_UpdateStringTable &table) {
      return true;
   }

   bool handleDemoPacket(const CDemoPacket &packet) {
      auto stream = std::istringstream { packet.data() };
      auto in = BinaryStream { stream };
      return parseSubMessage(in);
   }

   bool handleDemoFullPacket(const CDemoFullPacket &packet) {
      bool success = true;
      success &= handleDemoPacket(packet.packet());
      success &= handleStringTables(packet.string_table());
      return success;
   }

   bool handleDemoSendTables(const CDemoSendTables &packet) {
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

