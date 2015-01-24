#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct dota_chat_event
{
   int16_t userid;
   int16_t gold;
   int16_t message;
};

}

DeclareGameEvent(dota_chat_event);

}
