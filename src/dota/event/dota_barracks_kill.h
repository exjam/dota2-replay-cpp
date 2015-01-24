#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct dota_barracks_kill
{
   int16_t barracks_id;
};

}

DeclareGameEvent(dota_barracks_kill);

}
