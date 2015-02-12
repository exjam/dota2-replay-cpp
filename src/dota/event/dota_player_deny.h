#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct dota_player_deny
{
   int16_t killer_userid;
   int16_t victim_userid;
};

}

DeclareGameEvent(dota_player_deny);

}
