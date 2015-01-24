#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct dota_item_purchase
{
   int16_t userid;
   int16_t itemid;
};

}

DeclareGameEvent(dota_item_purchase);

}
