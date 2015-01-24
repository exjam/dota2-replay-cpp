#pragma once
#include <cstdint>
#include "gameevent.h"

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
