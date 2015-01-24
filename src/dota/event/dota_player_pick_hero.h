#pragma once
#include <cstdint>
#include <string>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct dota_player_pick_hero
{
   int16_t player;
   int16_t heroindex;
   std::string hero;
};

}

DeclareGameEvent(dota_player_pick_hero);

}
