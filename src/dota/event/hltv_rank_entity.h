#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct hltv_rank_entity
{
   int16_t index;
   float rank;
   int16_t target;
};

}

DeclareGameEvent(hltv_rank_entity);

}
