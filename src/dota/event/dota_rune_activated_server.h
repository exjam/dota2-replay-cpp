#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct dota_rune_activated_server
{
   int16_t PlayerID;
   int16_t rune;
};

}

DeclareGameEvent(dota_rune_activated_server);

}
