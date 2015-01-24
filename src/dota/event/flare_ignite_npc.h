#pragma once
#include <cstdint>
#include "gameevent.h"

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
