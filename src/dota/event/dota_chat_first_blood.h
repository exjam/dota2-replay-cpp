#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct dota_chat_first_blood
{
   int16_t gold;
   int16_t killer_id;
   int16_t victim_id;
};

}

DeclareGameEvent(dota_chat_first_blood);

}
