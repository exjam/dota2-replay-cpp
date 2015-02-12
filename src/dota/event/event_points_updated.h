#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct event_points_updated
{
   int16_t event_id;
   int16_t points;
   int16_t premium_points;
};

}

DeclareGameEvent(event_points_updated);

}
