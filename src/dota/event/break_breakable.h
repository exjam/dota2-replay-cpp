#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct break_breakable
{
   int32_t entindex;
   int16_t userid;
   uint8_t material;
};

}

DeclareGameEvent(break_breakable);

}
