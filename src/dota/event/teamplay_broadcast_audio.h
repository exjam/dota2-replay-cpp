#pragma once
#include <cstdint>
#include <string>
#include "event.h"

namespace dota
{

namespace event
{

struct teamplay_broadcast_audio
{
   uint8_t team;
   std::string sound;
};

}

DeclareGameEvent(teamplay_broadcast_audio);

}
