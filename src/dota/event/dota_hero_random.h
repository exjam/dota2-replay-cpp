#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct dota_hero_random
{
   int16_t userid;
   int16_t heroid;
};

}

DeclareGameEvent(dota_hero_random);

}
