#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct dota_inventory_item_changed
{
   int16_t entityIndex;
};

}

DeclareGameEvent(dota_inventory_item_changed);

}
