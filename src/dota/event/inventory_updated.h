#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct inventory_updated
{
   int16_t itemdef;
   int32_t itemid;
};

}

DeclareGameEvent(inventory_updated);

}
