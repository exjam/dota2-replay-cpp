#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct recent_matches_updated
{
   int16_t Page;
};

}

DeclareGameEvent(recent_matches_updated);

}
