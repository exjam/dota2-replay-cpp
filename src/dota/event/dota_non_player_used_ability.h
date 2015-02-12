#pragma once
#include <string>
#include "event.h"

namespace dota
{

namespace event
{

struct dota_non_player_used_ability
{
   std::string abilityname;
};

}

DeclareGameEvent(dota_non_player_used_ability);

}
