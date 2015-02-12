#pragma once
#include <string>
#include "event.h"

namespace dota
{

namespace event
{

struct server_shutdown
{
   std::string reason;
};

}

DeclareGameEvent(server_shutdown);

}
