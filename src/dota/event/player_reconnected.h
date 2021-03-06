#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct player_reconnected
{
   int16_t PlayerID;
};

}

DeclareGameEvent(player_reconnected);

}
