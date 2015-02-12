#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct physgun_pickup
{
   int32_t entindex;
};

}

DeclareGameEvent(physgun_pickup);

}
