#pragma once
#include <cstdint>
#include <string>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct dota_player_used_ability
{
   int16_t PlayerID;
   std::string abilityname;
};

}

DeclareGameEvent(dota_player_used_ability);

}
