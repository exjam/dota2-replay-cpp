#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct dota_hero_swap
{
   uint8_t playerid1;
   uint8_t playerid2;
};

}

DeclareGameEvent(dota_hero_swap);

}
