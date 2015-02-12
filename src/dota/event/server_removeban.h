#pragma once
#include <string>
#include "event.h"

namespace dota
{

namespace event
{

struct server_removeban
{
   std::string networkid;
   std::string ip;
   std::string by;
};

}

DeclareGameEvent(server_removeban);

}
