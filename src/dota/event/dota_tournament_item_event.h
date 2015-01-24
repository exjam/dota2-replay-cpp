#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct dota_tournament_item_event
{
   int16_t winner_count;
   int16_t event_type;
};

}

DeclareGameEvent(dota_tournament_item_event);

}
