#include "binarystream.h"
#include "demoparser.h"
#include "entity/CBaseEntity.h"

namespace dota
{

bool DemoParser::parse(BinaryStream &in, const ParseProfile *profile)
{
   auto header = in.readString(8);
   header.resize(7);

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
      mEventListeners.onTick(tick);
   }
}

void DemoParser::onGameEvent(dota::GameEventID type, const dota::GameEvent *event)
{
   if (mEventListeners.onGameEvent) {
      mEventListeners.onGameEvent(type, event);
   }
}

void DemoParser::setOnTickEventListener(TickEventListener listener)
{
   mEventListeners.onTick = listener;
}

void DemoParser::setOnGameEventListener(GameEventListener listener)
{
   mEventListeners.onGameEvent = listener;
}

void DemoParser::setOnEntityEnterListener(EntityEventListener listener)
{
   mEventListeners.onEntityEnter = listener;
}

void DemoParser::setOnEntityLeaveListener(EntityEventListener listener)
{
   mEventListeners.onEntityLeave = listener;
}

void DemoParser::setOnEntityPreserveListener(EntityEventListener listener)
{
   mEventListeners.onEntityPreserve = listener;
}

void DemoParser::setOnEntityDeleteListener(EntityEventListener listener)
{
   mEventListeners.onEntityDelete = listener;
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

const GameEventDescriptorList &DemoParser::gameEventDescriptors() const
{
   return mGameEventDescriptors;
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
