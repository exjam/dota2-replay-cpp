#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct hltv_chase
{
   int16_t target1;
   int16_t target2;
   int16_t distance;
   int16_t theta;
   int16_t phi;
   uint8_t inertia;
   uint8_t ineye;
};

}

DeclareGameEvent(hltv_chase);

}
