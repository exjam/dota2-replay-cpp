#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct dota_chase_hero
{
   int16_t target1;
   int16_t target2;
   uint8_t type;
   int16_t priority;
   float gametime;
   bool highlight;
   uint8_t target1playerid;
   uint8_t target2playerid;
   int16_t eventtype;
};

}

DeclareGameEvent(dota_chase_hero);

}
