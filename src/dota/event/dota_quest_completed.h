#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct dota_quest_completed
{
   int32_t questIndex;
};

}

DeclareGameEvent(dota_quest_completed);

}
