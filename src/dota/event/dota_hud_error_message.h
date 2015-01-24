#pragma once
#include <cstdint>
#include <string>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct dota_hud_error_message
{
   uint8_t reason;
   std::string message;
};

}

DeclareGameEvent(dota_hud_error_message);

}
