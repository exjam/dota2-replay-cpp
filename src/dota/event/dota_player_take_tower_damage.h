#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct dota_player_take_tower_damage
{
   int16_t PlayerID;
   int16_t damage;
};

}

DeclareGameEvent(dota_player_take_tower_damage);

}
