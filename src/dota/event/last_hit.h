#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct last_hit
{
   int16_t PlayerID;
   int16_t EntKilled;
   bool FirstBlood;
   bool HeroKill;
   bool TowerKill;
};

}

DeclareGameEvent(last_hit);

}
