#pragma once
#include <string>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct dota_inventory_item_added
{
   std::string itemname;
};

}

DeclareGameEvent(dota_inventory_item_added);

}
