#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct player_hurt
{
   int16_t userid;
   int16_t attacker;
   uint8_t health;
};

}

DeclareGameEvent(player_hurt);

}
