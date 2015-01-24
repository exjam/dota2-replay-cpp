#pragma once
#include <string>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct server_pre_shutdown
{
   std::string reason;
};

}

DeclareGameEvent(server_pre_shutdown);

}
