#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct today_messages_updated
{
   int16_t num_messages;
};

}

DeclareGameEvent(today_messages_updated);

}
