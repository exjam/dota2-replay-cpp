#pragma once
#include <cstdint>
#include "event.h"

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
