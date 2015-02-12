#pragma once
#include <cstdint>
#include "event.h"

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
