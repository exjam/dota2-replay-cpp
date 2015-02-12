#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct dota_courier_respawned
{
   int16_t teamnumber;
};

}

DeclareGameEvent(dota_courier_respawned);

}
