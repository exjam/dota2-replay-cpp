#pragma once
#include <string>
#include "event.h"

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
