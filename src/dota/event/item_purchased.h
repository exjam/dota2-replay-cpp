#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct item_purchased
{
   int16_t itemid;
};

}

DeclareGameEvent(item_purchased);

}
