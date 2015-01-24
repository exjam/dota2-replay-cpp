#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct dota_rubick_ability_steal
{
   int16_t abilityIndex;
   uint8_t abilityLevel;
};

}

DeclareGameEvent(dota_rubick_ability_steal);

}
