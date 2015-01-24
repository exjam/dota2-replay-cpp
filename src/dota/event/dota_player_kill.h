#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct dota_player_kill
{
   int16_t victim_userid;
   int16_t killer1_userid;
   int16_t killer2_userid;
   int16_t killer3_userid;
   int16_t killer4_userid;
   int16_t killer5_userid;
   int16_t bounty;
   int16_t neutral;
   int16_t greevil;
};

}

DeclareGameEvent(dota_player_kill);

}
