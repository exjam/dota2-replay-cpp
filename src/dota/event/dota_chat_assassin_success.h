#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct dota_chat_assassin_success
{
   int16_t assassin_id;
   int16_t target_id;
   int16_t message;
};

}

DeclareGameEvent(dota_chat_assassin_success);

}