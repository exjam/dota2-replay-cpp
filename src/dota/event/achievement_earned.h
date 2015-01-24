#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct achievement_earned
{
   uint8_t player;
   int16_t achievement;
};

}

DeclareGameEvent(achievement_earned);

}
