#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct finale_start
{
   int16_t rushes;
};

}

DeclareGameEvent(finale_start);

}
