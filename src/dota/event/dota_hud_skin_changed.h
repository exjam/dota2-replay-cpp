#pragma once
#include <cstdint>
#include <string>
#include "event.h"

namespace dota
{

namespace event
{

struct dota_hud_skin_changed
{
   std::string skin;
   uint8_t style;
};

}

DeclareGameEvent(dota_hud_skin_changed);

}
