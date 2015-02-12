#pragma once
#include <cstdint>
#include <string>
#include "event.h"

namespace dota
{

namespace event
{

struct round_start
{
   int32_t timelimit;
   int32_t fraglimit;
   std::string objective;
};

}

DeclareGameEvent(round_start);

}
