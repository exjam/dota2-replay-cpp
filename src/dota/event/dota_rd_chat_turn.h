#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct dota_rd_chat_turn
{
   int16_t userid;
};

}

DeclareGameEvent(dota_rd_chat_turn);

}
