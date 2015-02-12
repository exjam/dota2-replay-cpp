#pragma once
#include <cstdint>
#include <string>
#include "event.h"

namespace dota
{

namespace event
{

struct round_end
{
   uint8_t winner;
   uint8_t reason;
   std::string message;
};

}

DeclareGameEvent(round_end);

}
