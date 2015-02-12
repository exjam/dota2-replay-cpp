#pragma once
#include "event.h"

namespace dota
{

namespace event
{

struct player_stats_updated
{
   bool forceupload;
};

}

DeclareGameEvent(player_stats_updated);

}
