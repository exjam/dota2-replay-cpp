#pragma once
#include <cstdint>
#include <string>
#include "event.h"

namespace dota
{

namespace event
{

struct player_connect
{
   std::string name;
   uint8_t index;
   int16_t userid;
   std::string networkid;
   std::string address;
};

}

DeclareGameEvent(player_connect);

}
