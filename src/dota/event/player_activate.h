#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct player_activate
{
   int16_t userid;
};

}

DeclareGameEvent(player_activate);

}
