#pragma once
#include <string>
#include "gameevent.h"

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
