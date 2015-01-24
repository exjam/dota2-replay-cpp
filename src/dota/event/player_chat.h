#pragma once
#include <cstdint>
#include <string>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct player_chat
{
   bool teamonly;
   int16_t userid;
   std::string text;
};

}

DeclareGameEvent(player_chat);

}
