#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct chat_members_changed
{
   uint8_t channel;
};

}

DeclareGameEvent(chat_members_changed);

}
