#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct dota_action_item
{
   int16_t reason;
   int16_t itemdef;
   int16_t message;
};

}

DeclareGameEvent(dota_action_item);

}
