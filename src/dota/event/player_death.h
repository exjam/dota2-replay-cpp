#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct player_death
{
   int16_t userid;
   int16_t attacker;
};

}

DeclareGameEvent(player_death);

}
