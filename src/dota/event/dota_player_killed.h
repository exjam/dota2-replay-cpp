#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct dota_player_killed
{
   int16_t PlayerID;
   bool HeroKill;
   bool TowerKill;
};

}

DeclareGameEvent(dota_player_killed);

}
