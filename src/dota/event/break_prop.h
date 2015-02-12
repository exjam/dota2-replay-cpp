#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct break_prop
{
   int32_t entindex;
   int16_t userid;
};

}

DeclareGameEvent(break_prop);

}
