#pragma once
#include <cstdint>
#include <string>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct achievement_event
{
   std::string achievement_name;
   int16_t cur_val;
   int16_t max_val;
};

}

DeclareGameEvent(achievement_event);

}
