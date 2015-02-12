#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct npc_replaced
{
   int32_t old_entindex;
   int32_t new_entindex;
};

}

DeclareGameEvent(npc_replaced);

}
