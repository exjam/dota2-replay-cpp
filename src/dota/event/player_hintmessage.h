#pragma once
#include <string>
#include "event.h"

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
