#pragma once
#include <cstdint>
#include <string>
#include "event.h"

namespace dota
{

namespace event
{

struct game_message
{
   uint8_t target;
   std::string text;
};

}

DeclareGameEvent(game_message);

}
