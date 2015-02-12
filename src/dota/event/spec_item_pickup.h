#pragma once
#include <cstdint>
#include <string>
#include "event.h"

namespace dota
{

namespace event
{

struct spec_item_pickup
{
   int16_t player_id;
   std::string item_name;
   bool purchase;
};

}

DeclareGameEvent(spec_item_pickup);

}
