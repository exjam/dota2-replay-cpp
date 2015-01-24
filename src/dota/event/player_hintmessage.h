#pragma once
#include <string>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct player_hintmessage
{
   std::string hintmessage;
};

}

DeclareGameEvent(player_hintmessage);

}
