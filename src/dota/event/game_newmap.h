#pragma once
#include <string>
#include "event.h"

namespace dota
{

namespace event
{

struct game_newmap
{
   std::string mapname;
};

}

DeclareGameEvent(game_newmap);

}
