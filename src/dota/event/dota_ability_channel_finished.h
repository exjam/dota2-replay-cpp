#pragma once
#include <string>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct dota_ability_channel_finished
{
   std::string abilityname;
   bool interrupted;
};

}

DeclareGameEvent(dota_ability_channel_finished);

}
