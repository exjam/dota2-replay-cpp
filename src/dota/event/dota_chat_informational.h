#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct dota_chat_informational
{
   int16_t userid;
   int16_t type;
};

}

DeclareGameEvent(dota_chat_informational);

}
