#pragma once
#include <string>
#include "event.h"

namespace dota
{

namespace event
{

struct dota_inventory_player_got_item
{
   std::string itemname;
};

}

DeclareGameEvent(dota_inventory_player_got_item);

}
