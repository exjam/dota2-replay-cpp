#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct dashboard_switched_section
{
   int16_t section;
};

}

DeclareGameEvent(dashboard_switched_section);

}
