#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct player_use
{
   int16_t userid;
   int16_t entity;
};

}

DeclareGameEvent(player_use);

}
