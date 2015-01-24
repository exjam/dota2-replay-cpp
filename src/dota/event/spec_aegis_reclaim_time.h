#pragma once
#include "gameevent.h"

namespace dota
{

namespace event
{

struct spec_aegis_reclaim_time
{
   float reclaim_time;
};

}

DeclareGameEvent(spec_aegis_reclaim_time);

}
