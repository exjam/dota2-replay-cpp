#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct match_details_updated
{
   uint64_t matchID;
   uint8_t result;
};

}

DeclareGameEvent(match_details_updated);

}
