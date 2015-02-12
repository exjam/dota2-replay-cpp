#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct player_spawn
{
   int16_t userid;
};

}

DeclareGameEvent(player_spawn);

}
