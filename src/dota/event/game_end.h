#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct game_end
{
   uint8_t winner;
};

}

DeclareGameEvent(game_end);

}
