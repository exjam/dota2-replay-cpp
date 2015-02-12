#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct dota_player_shop_changed
{
   uint8_t prevshopmask;
   uint8_t shopmask;
};

}

DeclareGameEvent(dota_player_shop_changed);

}
