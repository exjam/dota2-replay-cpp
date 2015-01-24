#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct compendium_event_actions_loaded
{
   uint64_t account_id;
   uint64_t league_id;
   bool local_test;
   uint64_t original_points;
};

}

DeclareGameEvent(compendium_event_actions_loaded);

}
