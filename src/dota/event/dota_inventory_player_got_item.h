#pragma once
#include <string>
#include "gameevent.h"

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
