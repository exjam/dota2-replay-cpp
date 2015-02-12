#pragma once
#include <cstdint>
#include <string>
#include "event.h"

namespace dota
{

namespace event
{

struct dota_quick_buy_changed
{
   std::string item;
   uint8_t recipe;
};

}

DeclareGameEvent(dota_quick_buy_changed);

}
