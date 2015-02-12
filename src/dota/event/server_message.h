#pragma once
#include <string>
#include "event.h"

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
