#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct chat_new_message
{
   uint8_t channel;
};

}

DeclareGameEvent(chat_new_message);

}
