#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct player_completed_game
{
   int16_t PlayerID;
   uint8_t Winner;
};

}

DeclareGameEvent(player_completed_game);

}
