#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct dota_game_state_change
{
   int16_t old_state;
   int16_t new_state;
};

}

DeclareGameEvent(dota_game_state_change);

}
