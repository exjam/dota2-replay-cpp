#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct dota_unit_event
{
   int16_t victim;
   int16_t attacker;
   int16_t basepriority;
   int16_t priority;
   int16_t eventtype;
};

}

DeclareGameEvent(dota_unit_event);

}
