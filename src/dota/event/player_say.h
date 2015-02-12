#pragma once
#include <cstdint>
#include <string>
#include "event.h"

namespace dota
{

namespace event
{

struct player_say
{
   int16_t userid;
   std::string text;
};

}

DeclareGameEvent(player_say);

}
