#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct dota_rune_pickup
{
   int16_t userid;
   int16_t type;
   int16_t rune;
};

}

DeclareGameEvent(dota_rune_pickup);

}
