#pragma once
#include "event.h"

namespace dota
{

namespace event
{

struct dota_player_update_hero_selection
{
   bool tabcycle;
};

}

DeclareGameEvent(dota_player_update_hero_selection);

}
