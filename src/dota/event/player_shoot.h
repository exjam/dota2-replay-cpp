#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct player_shoot
{
   int16_t userid;
   uint8_t weapon;
   uint8_t mode;
};

}

DeclareGameEvent(player_shoot);

}
