#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct player_report_counts_updated
{
   uint8_t positive_remaining;
   uint8_t negative_remaining;
   int16_t positive_total;
   int16_t negative_total;
};

}

DeclareGameEvent(player_report_counts_updated);

}
