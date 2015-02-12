#pragma once
#include <cstdint>
#include <string>
#include "event.h"

namespace dota
{

namespace event
{

struct difficulty_changed
{
   int16_t newDifficulty;
   int16_t oldDifficulty;
   std::string strDifficulty;
};

}

DeclareGameEvent(difficulty_changed);

}
