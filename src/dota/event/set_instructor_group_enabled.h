#pragma once
#include <cstdint>
#include <string>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct set_instructor_group_enabled
{
   std::string group;
   int16_t enabled;
};

}

DeclareGameEvent(set_instructor_group_enabled);

}
