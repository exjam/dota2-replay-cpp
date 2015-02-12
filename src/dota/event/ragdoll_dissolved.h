#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct ragdoll_dissolved
{
   int32_t entindex;
};

}

DeclareGameEvent(ragdoll_dissolved);

}
