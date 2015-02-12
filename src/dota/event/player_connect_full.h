#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct player_connect_full
{
   int16_t userid;
   uint8_t index;
};

}

DeclareGameEvent(player_connect_full);

}
