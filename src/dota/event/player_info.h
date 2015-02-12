#pragma once
#include <cstdint>
#include <string>
#include "event.h"

namespace dota
{

namespace event
{

struct player_info
{
   std::string name;
   uint8_t index;
   int16_t userid;
   std::string networkid;
   bool bot;
};

}

DeclareGameEvent(player_info);

}
