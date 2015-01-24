#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct prizepool_received
{
   bool success;
   uint64_t prizepool;
   uint64_t leagueid;
};

}

DeclareGameEvent(prizepool_received);

}
