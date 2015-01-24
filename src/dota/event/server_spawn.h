#pragma once
#include <cstdint>
#include <string>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct server_spawn
{
   std::string hostname;
   std::string address;
   int16_t port;
   std::string game;
   std::string mapname;
   std::string addonname;
   int32_t maxplayers;
   std::string os;
   bool dedicated;
   bool password;
};

}

DeclareGameEvent(server_spawn);

}
