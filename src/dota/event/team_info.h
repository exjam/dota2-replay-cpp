#pragma once
#include <cstdint>
#include <string>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct team_info
{
   uint8_t teamid;
   std::string teamname;
};

}

DeclareGameEvent(team_info);

}
