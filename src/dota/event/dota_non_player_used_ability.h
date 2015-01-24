#pragma once
#include <string>
#include "gameevent.h"

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
