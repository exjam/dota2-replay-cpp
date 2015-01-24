#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct dota_quest_started
{
   int32_t questIndex;
};

}

DeclareGameEvent(dota_quest_started);

}
