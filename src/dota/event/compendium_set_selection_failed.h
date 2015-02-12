#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct compendium_set_selection_failed
{
   uint64_t account_id;
   uint64_t league_id;
   bool local_test;
};

}

DeclareGameEvent(compendium_set_selection_failed);

}
