#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct npc_spawned
{
   int32_t entindex;
};

}

DeclareGameEvent(npc_spawned);

}
