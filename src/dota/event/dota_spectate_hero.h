#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct dota_spectate_hero
{
   uint8_t entindex;
};

}

DeclareGameEvent(dota_spectate_hero);

}
