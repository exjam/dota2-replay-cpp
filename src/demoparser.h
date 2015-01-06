#pragma once

#include <vector>
#include <map>

#include "property.h"
#include "propertyvariant.h"

#include "entity.h"
#include "sendtable.h"
#include "receivetable.h"
#include "stringtable.h"

struct ClassInfo
{
   std::size_t id;
   std::string name;
   std::string tableName;
};

struct ServerInfo
{
   std::size_t maxClasses;
   float tickInterval;
};

class BinaryStream;
class BitStream;

class CDemoClassInfo;
class CDemoFileHeader;
class CDemoFileInfo;
class CDemoFullPacket;
class CDemoPacket;
class CDemoSendTables;
class CDemoStringTables;
class CDemoSyncTick;
class CDOTAUserMsg_CourierKilledAlert;
class CSVCMsg_CreateStringTable;
class CSVCMsg_UpdateStringTable;
class CSVCMsg_PacketEntities;
class CSVCMsg_ServerInfo;
class CSVCMsg_SendTable;
class CSVCMsg_UserMessage;
class CSVCMsg_ClassInfo;

using ReceiveTableMap = std::map<std::string, ReceiveTable>;
using SendTableMap = std::map<std::string, SendTable>;
using StringTableMap = std::map<std::string, StringTable>;

class DemoParser
{
   ServerInfo mServerInfo;
   std::vector<ClassInfo> mClassInfo;
   std::map<unsigned, Entity> mEntities;
   SendTableMap mSendTables;
   ReceiveTableMap mReceiveTables;
   StringTableMap mStringTables;

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

   bool flattenSendTable(SendTable &sendTable);
   bool parsePacketEntities(const CSVCMsg_PacketEntities &msg);
   bool parsePropertyVariant(BitStream &in, Property &prop, PropertyVariant &variant);
   bool parseStringTable(StringTable &table, BitStream &in, std::size_t entries);

   bool handleDemoClassInfo(const CDemoClassInfo &info);
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
   bool handleCourierKilledAlert(const CDOTAUserMsg_CourierKilledAlert &msg);
};
