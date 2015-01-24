#pragma once
#include <string>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct instructor_server_hint_stop
{
   std::string hint_name;
};

}

DeclareGameEvent(instructor_server_hint_stop);

}
