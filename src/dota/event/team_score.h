#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct team_score
{
   uint8_t teamid;
   int16_t score;
};

}

DeclareGameEvent(team_score);

}
