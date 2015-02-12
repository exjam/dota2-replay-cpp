#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct dota_player_gained_level
{
   int16_t PlayerID;
   int16_t level;
};

}

DeclareGameEvent(dota_player_gained_level);

}
