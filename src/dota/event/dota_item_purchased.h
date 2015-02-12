#pragma once
#include <cstdint>
#include <string>
#include "event.h"

namespace dota
{

namespace event
{

struct dota_item_purchased
{
   int16_t PlayerID;
   std::string itemname;
   int16_t itemcost;
};

}

DeclareGameEvent(dota_item_purchased);

}
