#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct player_score
{
   int16_t userid;
   int16_t kills;
   int16_t deaths;
   int16_t score;
};

}

DeclareGameEvent(player_score);

}
