#include "parseprofile.h"

#include "proto/demo.pb.h"
#include "proto/dota_usermessages.pb.h"
#include "proto/netmessages.pb.h"
#include "proto/usermessages.pb.h"

namespace dota
{

const ParseProfile *ParseProfile::SendTables = new ParseProfile
{
   { DEM_ClassInfo },
   { svc_SendTable, svc_ClassInfo },
   { }
};

const ParseProfile *ParseProfile::StringTables = new ParseProfile
{
   { DEM_StringTables },
   { svc_CreateStringTable, svc_UpdateStringTable },
   { }
};

const ParseProfile *ParseProfile::Entities = new ParseProfile
{
   { },
   { svc_PacketEntities },
   { },
   { ParseProfile::SendTables, ParseProfile::StringTables }
};

const ParseProfile *ParseProfile::TempEntities = new ParseProfile
{
   { },
   { svc_TempEntities },
   { },
   { ParseProfile::SendTables, ParseProfile::StringTables }
};

const ParseProfile *ParseProfile::GameEventDescriptors = new ParseProfile
{
   { },
   { svc_GameEventList },
   { }
};

const ParseProfile *ParseProfile::GameEvents = new ParseProfile
{
   { },
   { svc_GameEvent },
   { },
   { ParseProfile::GameEventDescriptors }
};

const ParseProfile *ParseProfile::UserMessages = new ParseProfile
{
   { },
   { svc_UserMessage },
   { },
   { }
};

const ParseProfile *ParseProfile::FullReplay = new ParseProfile
{
   { },
   { },
   { },
   { ParseProfile::UserMessages, ParseProfile::GameEvents, ParseProfile::Entities, ParseProfile::TempEntities }
};

ParseProfile::ParseProfile()
{
   msg.fill(false);
   sub.fill(false);

   // Enable all user messages, as they are filtered by svc_UserMessage
   usr.fill(true);

   // Always parse information messages
   msg[DEM_FileHeader] = true;
   msg[DEM_FileInfo] = true;
   msg[DEM_SyncTick] = true;
   sub[net_SetConVar] = true;
   sub[net_SignonState] = true;
   sub[svc_ServerInfo] = true;

   // Always parse container messages
   msg[DEM_SendTables] = true;
   msg[DEM_Packet] = true;
   msg[DEM_SignonPacket] = true;
   msg[DEM_FullPacket] = true;
}

ParseProfile::ParseProfile(std::vector<const ParseProfile *> bases) :
   ParseProfile()
{
   for (auto &base : bases) {
      for (auto i = 0; i < msg.size(); ++i) {
         msg[i] = msg[i] | base->msg[i];
      }

      for (auto i = 0; i < sub.size(); ++i) {
         sub[i] = sub[i] | base->sub[i];
      }

      for (auto i = 0; i < usr.size(); ++i) {
         usr[i] = usr[i] | base->usr[i];
      }
   }
}

ParseProfile::ParseProfile(std::vector<int> allowMsg,
                           std::vector<int> allowSub,
                           std::vector<int> allowUsr,
                           std::vector<const ParseProfile *> bases)
   : ParseProfile(bases)
{
   for (auto &id : allowMsg) {
      msg[id] = true;
   }

   for (auto &id : allowSub) {
      sub[id] = true;
   }

   for (auto &id : allowUsr) {
      usr[id] = true;
   }
}

}