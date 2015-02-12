#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct dota_no_battle_points
{
   int16_t userid;
   int16_t reason;
};

}

DeclareGameEvent(dota_no_battle_points);

}
