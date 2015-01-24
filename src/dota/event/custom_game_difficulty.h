#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct custom_game_difficulty
{
   uint8_t difficulty;
};

}

DeclareGameEvent(custom_game_difficulty);

}
