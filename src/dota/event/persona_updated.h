#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct persona_updated
{
   uint64_t SteamID;
};

}

DeclareGameEvent(persona_updated);

}
