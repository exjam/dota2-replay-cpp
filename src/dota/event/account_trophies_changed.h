#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct account_trophies_changed
{
   uint64_t account_id;
};

}

DeclareGameEvent(account_trophies_changed);

}
