#pragma once
#include <cstdint>
#include "event.h"

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
