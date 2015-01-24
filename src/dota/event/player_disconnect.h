#pragma once
#include <cstdint>
#include <string>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct player_disconnect
{
   int16_t userid;
   int16_t reason;
   std::string name;
   std::string networkid;
};

}

DeclareGameEvent(player_disconnect);

}
