#pragma once
#include <cstdint>
#include <string>
#include "event.h"

namespace dota
{

namespace event
{

struct player_fullyjoined
{
   int16_t userid;
   std::string name;
};

}

DeclareGameEvent(player_fullyjoined);

}
