#pragma once
#include <cstdint>
#include <string>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct player_changename
{
   int16_t userid;
   std::string oldname;
   std::string newname;
};

}

DeclareGameEvent(player_changename);

}
