#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct match_history_updated
{
   uint64_t SteamID;
};

}

DeclareGameEvent(match_history_updated);

}
