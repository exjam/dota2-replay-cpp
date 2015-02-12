#pragma once
#include <cstdint>
#include "event.h"

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
