#pragma once
#include <cstdint>
#include <string>
#include "event.h"

namespace dota
{

namespace event
{

struct dota_item_picked_up
{
   std::string itemname;
   int16_t PlayerID;
   int16_t ItemEntityIndex;
   int16_t HeroEntityIndex;
};

}

DeclareGameEvent(dota_item_picked_up);

}
