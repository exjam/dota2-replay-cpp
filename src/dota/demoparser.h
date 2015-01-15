#pragma once
#include <map>
#include <vector>

#include "entity.h"
#include "entityclass.h"
#include "gameevent.h"
#include "property.h"
#include "propertyvariant.h"
#include "entityclass.h"
#include "sendtable.h"
#include "stringtable.h"

class BinaryStream;
class BitStream;

class CDemoClassInfo;
class CDemoConsoleCmd;
class CDemoFileHeader;
class CDemoFileInfo;
class CDemoFullPacket;
class CDemoPacket;
class CDemoSendTables;
class CDemoStringTables;
class CDemoSyncTick;
class CDOTAUserMsg_CourierKilledAlert;
class CDOTAUserMsg_AbilitySteal;
class CSVCMsg_CreateStringTable;
class CSVCMsg_UpdateStringTable;
class CSVCMsg_PacketEntities;
class CSVCMsg_ServerInfo;
class CSVCMsg_SendTable;
class CSVCMsg_UserMessage;
class CSVCMsg_ClassInfo;
class CSVCMsg_GameEvent;
class CSVCMsg_GameEventList;

namespace dota
{

struct ServerInfo
{
   std::size_t maxClasses;
   float tickInterval;
};

using SendTableMap = std::map<std::string, SendTable>;
using ClassTableMap = std::map<std::string, EntityClass*>;
using StringTableMap = std::map<std::string, StringTable>;

class DemoParser
{
public:
   ServerInfo mServerInfo;
   std::vector<EntityClass> mClassInfo;
   ClassTableMap mClassMap;
   std::vector<Entity> mEntities = std::vector<Entity>(2048);
   SendTableMap mSendTables;
   StringTableMap mStringTables;
   std::map<int, GameEventDescriptor> mGameEventDescriptors;
   CombatLogEventDescriptor mCombatLogEventDescriptor;

public:
   bool parse(BinaryStream &in);

protected:
   bool parseMessage(BinaryStream &in);
   bool parseSubMessage(BinaryStream &in);
   bool parseUserMessage(const CSVCMsg_UserMessage &message);

   template<typename Type, typename Handler>
   bool decodeMessage(const std::vector<uint8_t> &array, Handler handler)
   {
      Type message;

      if (!message.ParseFromArray(array.data(), array.size())) {
         return false;
      }

      return (this->*handler)(message);
   }

   template<typename Type, typename Handler>
   bool decodeMessage(const std::string &string, Handler handler)
   {
      Type message;

      if (!message.ParseFromString(string)) {
         return false;
      }

      return (this->*handler)(message);
   }

   bool flattenSendTable(SendTable &sendTable, ReceiveTable &receiveTable);
   bool parsePacketEntities(const CSVCMsg_PacketEntities &msg);
   bool parsePropertyVariant(BitStream &in, Property &prop, PropertyVariant &variant);
   bool parseStringTable(StringTable &table, BitStream &in, std::size_t entries);

   bool handleDemoClassInfo(const CDemoClassInfo &info);
   bool handleDemoConsoleCmd(const CDemoConsoleCmd &cmd);
   bool handleDemoFileInfo(const CDemoFileInfo &info);
   bool handleDemoSyncTick(const CDemoSyncTick &msg);
   bool handleDemoFileHeader(const CDemoFileHeader &header);
   bool handleStringTables(const CDemoStringTables &tables);
   bool handleSendTable(const CSVCMsg_SendTable &msg);
   bool handleClassInfo(const CSVCMsg_ClassInfo &msg);
   bool handleCreateStringTable(const CSVCMsg_CreateStringTable &msg);
   bool handleUpdateStringTable(const CSVCMsg_UpdateStringTable &msg);
   bool handleServerInfo(const CSVCMsg_ServerInfo &info);
   bool handleDemoPacket(const CDemoPacket &packet);
   bool handleDemoFullPacket(const CDemoFullPacket &packet);
   bool handleDemoSendTables(const CDemoSendTables &sendTables);
   bool handleDemoStringTables(const CDemoStringTables &stringTables);
   bool handleGameEvent(const CSVCMsg_GameEvent &event);
   bool handleCombatLog(const CSVCMsg_GameEvent &event);
   bool handleGameEventList(const CSVCMsg_GameEventList &list);

   bool handleAbilitySteal(const CDOTAUserMsg_AbilitySteal &msg);
   bool handleCourierKilledAlert(const CDOTAUserMsg_CourierKilledAlert &msg);
};

}
