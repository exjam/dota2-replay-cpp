#pragma once
#include <cstdint>
#include <string>
#include "event.h"

namespace dota
{

namespace event
{

struct dota_player_learned_ability
{
   int16_t PlayerID;
   std::string abilityname;
};

}

DeclareGameEvent(dota_player_learned_ability);

}
