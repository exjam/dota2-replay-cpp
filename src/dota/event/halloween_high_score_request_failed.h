#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct halloween_high_score_request_failed
{
   int16_t round;
};

}

DeclareGameEvent(halloween_high_score_request_failed);

}
