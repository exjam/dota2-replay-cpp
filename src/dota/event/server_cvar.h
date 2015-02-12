#pragma once
#include <string>
#include "event.h"

namespace dota
{

namespace event
{

struct server_cvar
{
   std::string cvarname;
   std::string cvarvalue;
};

}

DeclareGameEvent(server_cvar);

}
