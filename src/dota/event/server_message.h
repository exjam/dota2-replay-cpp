#pragma once
#include <string>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct server_message
{
   std::string text;
};

}

DeclareGameEvent(server_message);

}
