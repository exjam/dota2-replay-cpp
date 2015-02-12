#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct dota_item_spotted
{
   int16_t userid;
   int16_t itemid;
};

}

DeclareGameEvent(dota_item_spotted);

}
