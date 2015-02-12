#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct bonus_updated
{
   int16_t numadvanced;
   int16_t numbronze;
   int16_t numsilver;
   int16_t numgold;
};

}

DeclareGameEvent(bonus_updated);

}
