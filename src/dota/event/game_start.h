#pragma once
#include <cstdint>
#include <string>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct game_start
{
   int32_t roundslimit;
   int32_t timelimit;
   int32_t fraglimit;
   std::string objective;
};

}

DeclareGameEvent(game_start);

}
