#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct player_full_update
{
   int16_t userid;
   int16_t count;
};

}

DeclareGameEvent(player_full_update);

}
