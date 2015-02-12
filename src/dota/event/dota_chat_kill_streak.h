#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct dota_chat_kill_streak
{
   int16_t gold;
   int16_t killer_id;
   int16_t killer_streak;
   int16_t killer_multikill;
   int16_t victim_id;
   int16_t victim_streak;
};

}

DeclareGameEvent(dota_chat_kill_streak);

}
