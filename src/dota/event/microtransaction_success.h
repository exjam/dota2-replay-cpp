#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct microtransaction_success
{
   uint64_t txnid;
};

}

DeclareGameEvent(microtransaction_success);

}
