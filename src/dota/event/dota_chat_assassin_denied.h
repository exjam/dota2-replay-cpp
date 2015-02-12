#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct dota_chat_assassin_denied
{
   int16_t assassin_id;
   int16_t target_id;
   int16_t message;
};

}

DeclareGameEvent(dota_chat_assassin_denied);

}
