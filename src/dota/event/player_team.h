#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct player_team
{
   int16_t userid;
   uint8_t team;
   uint8_t oldteam;
   bool disconnect;
   bool autoteam;
   bool silent;
};

}

DeclareGameEvent(player_team);

}
