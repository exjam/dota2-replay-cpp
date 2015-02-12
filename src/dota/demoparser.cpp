#include "byteview.h"
#include "demoparser.h"
#include "entity/CBaseEntity.h"

namespace dota
{

bool DemoParser::parse(ByteView &in, const ParseProfile *profile)
{
   auto header = in.readStringView(8);

   if (header.compare("PBUFDEM") != 0) {
      return 0;
   }

   mParseProfile = profile;

   // Read CDemoFileInfo
   auto offset = in.read<uint32_t>();
   auto pos = in.tell();
   in.seek(offset);
   parseMessage(in);

   // Read game messages
   in.seek(pos);

   while (!in.eof()) {
      parseMessage(in);
   }

   return true;
}

void DemoParser::onTick(Tick tick)
{
   if (mEventListeners.onTick) {
      mEventListeners.onTick(tick, mTickData);
   }

   // Clean up any tick data
   mTickData.enterEntity.clear();
   mTickData.deleteEntity.clear();

   // Destroy the dynamically allocated clientEvents
   for (auto &event : mTickData.events) {
      if (event.classInfo && event.classInfo->clientEventClass && event.clientEvent) {
         event.classInfo->clientEventClass->destroy(event.clientEvent);
      }
   }

   mTickData.events.clear();
}

void DemoParser::setOnTickEventListener(TickEventListener listener)
{
   mEventListeners.onTick = listener;
}

const ServerInfo &DemoParser::serverInfo() const
{
   return mServerInfo;
}

const GameInfo &DemoParser::gameInfo() const
{
   return mGameInfo;
}

const FileHeader &DemoParser::fileHeader() const
{
   return mFileHeader;
}

const SignonStateInfo &DemoParser::signonState() const
{
   return mSignonState;
}

const ClassList &DemoParser::classList() const
{
   return mClassList;
}

const EventDescriptorList &DemoParser::eventDescriptors() const
{
   return mEventDescriptors;
}

StringTable *DemoParser::findStringTableByName(const std::string &name)
{
   auto itr = mStringTables.find(name);

   if (itr == mStringTables.end()) {
      return nullptr;
   }

   return &itr->second;
}

StringTable *DemoParser::findStringTableByID(int id)
{
   for (auto &&itr : mStringTables) {
      if (itr.second.id == id) {
         return &itr.second;
      }
   }

   return nullptr;
}

EntityClass *DemoParser::findClassByTableName(const std::string &name)
{
   auto itr = mClassTableMap.find(name);

   if (itr == mClassTableMap.end()) {
      return nullptr;
   }

   return itr->second;
}

SendTable *DemoParser::findSendTableByName(const std::string &name)
{
   auto itr = mSendTables.find(name);

   if (itr == mSendTables.end()) {
      return nullptr;
   }

   return &itr->second;
}

}
