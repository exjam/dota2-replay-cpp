#pragma once
#include <string>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct hostname_changed
{
   std::string hostname;
};

}

DeclareGameEvent(hostname_changed);

}
