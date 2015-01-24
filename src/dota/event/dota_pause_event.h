#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct dota_pause_event
{
   int16_t userid;
   int16_t value;
   int16_t message;
};

}

DeclareGameEvent(dota_pause_event);

}
