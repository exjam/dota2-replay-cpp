#pragma once
#include <string>
#include "gameevent.h"

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
