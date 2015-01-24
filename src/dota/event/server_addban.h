#pragma once
#include <cstdint>
#include <string>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct server_addban
{
   std::string name;
   int16_t userid;
   std::string networkid;
   std::string ip;
   std::string duration;
   std::string by;
   bool kicked;
};

}

DeclareGameEvent(server_addban);

}
