#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct dota_chat_timed_reward
{
   int16_t userid;
   int16_t itmedef;
   int16_t message;
};

}

DeclareGameEvent(dota_chat_timed_reward);

}
