#pragma once
#include <cstdint>
#include <string>
#include "event.h"

namespace dota
{

namespace event
{

struct player_class
{
   int16_t userid;
   std::string class_;
};

}

DeclareGameEvent(player_class);

}
