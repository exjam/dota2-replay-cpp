#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct dota_courier_lost
{
   int16_t teamnumber;
};

}

DeclareGameEvent(dota_courier_lost);

}
