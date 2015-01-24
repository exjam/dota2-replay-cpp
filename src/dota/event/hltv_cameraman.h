#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct hltv_cameraman
{
   int16_t index;
};

}

DeclareGameEvent(hltv_cameraman);

}
