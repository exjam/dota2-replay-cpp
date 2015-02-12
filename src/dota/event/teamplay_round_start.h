#pragma once
#include "event.h"

namespace dota
{

namespace event
{

struct teamplay_round_start
{
   bool full_reset;
};

}

DeclareGameEvent(teamplay_round_start);

}
