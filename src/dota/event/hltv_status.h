#pragma once
#include <cstdint>
#include <string>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct hltv_status
{
   int32_t clients;
   int32_t slots;
   int16_t proxies;
   std::string master;
};

}

DeclareGameEvent(hltv_status);

}
