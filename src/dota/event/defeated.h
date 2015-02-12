#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct defeated
{
   int16_t entindex;
};

}

DeclareGameEvent(defeated);

}
