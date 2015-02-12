#pragma once
#include <cstdint>
#include "event.h"

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
