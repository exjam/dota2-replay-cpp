#pragma once
#include <cstdint>
#include <string>
#include "event.h"

namespace dota
{

namespace event
{

struct modifier_event
{
   std::string eventname;
   int16_t caster;
   int16_t ability;
};

}

DeclareGameEvent(modifier_event);

}
