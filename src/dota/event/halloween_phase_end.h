#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct halloween_phase_end
{
   uint8_t phase;
   uint8_t team;
};

}

DeclareGameEvent(halloween_phase_end);

}
