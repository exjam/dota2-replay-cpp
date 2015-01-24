#pragma once
#include <cstdint>
#include "gameevent.h"

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
