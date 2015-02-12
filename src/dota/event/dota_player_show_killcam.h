#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct dota_player_show_killcam
{
   uint8_t nodes;
   int16_t player;
};

}

DeclareGameEvent(dota_player_show_killcam);

}
