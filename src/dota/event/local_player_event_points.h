#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct local_player_event_points
{
   int16_t points;
   int16_t conversion_rate;
};

}

DeclareGameEvent(local_player_event_points);

}
