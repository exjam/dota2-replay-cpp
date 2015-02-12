#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct dota_item_gifted
{
   int16_t userid;
   int16_t itemid;
   int16_t sourceid;
};

}

DeclareGameEvent(dota_item_gifted);

}
