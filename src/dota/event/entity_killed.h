#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct entity_killed
{
   int32_t entindex_killed;
   int32_t entindex_attacker;
   int32_t entindex_inflictor;
   int32_t damagebits;
};

}

DeclareGameEvent(entity_killed);

}
