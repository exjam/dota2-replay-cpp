#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct dota_combatlog
{
   uint8_t type;
   int16_t sourcename;
   int16_t targetname;
   int16_t attackername;
   int16_t inflictorname;
   bool attackerillusion;
   bool targetillusion;
   int16_t value;
   int16_t health;
   float timestamp;
   int16_t targetsourcename;
   float timestampraw;
   bool attackerhero;
   bool targethero;
   bool ability_toggle_on;
   bool ability_toggle_off;
   int16_t ability_level;
   int16_t gold_reason;
   int16_t xp_reason;
};

}

DeclareGameEvent(dota_combatlog);

}
