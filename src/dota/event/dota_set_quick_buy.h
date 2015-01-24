#pragma once
#include <cstdint>
#include <string>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct dota_set_quick_buy
{
   std::string item;
   uint8_t recipe;
   bool toggle;
};

}

DeclareGameEvent(dota_set_quick_buy);

}
