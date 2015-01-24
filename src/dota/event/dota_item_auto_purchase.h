#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct dota_item_auto_purchase
{
   int16_t item_id;
};

}

DeclareGameEvent(dota_item_auto_purchase);

}
