#pragma once
#include <cstdint>
#include <string>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct dota_item_used
{
   int16_t PlayerID;
   std::string itemname;
};

}

DeclareGameEvent(dota_item_used);

}
