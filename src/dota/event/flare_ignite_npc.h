#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct flare_ignite_npc
{
   int32_t entindex;
};

}

DeclareGameEvent(flare_ignite_npc);

}
