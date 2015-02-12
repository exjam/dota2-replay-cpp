#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct dota_roshan_kill
{
   int16_t teamnumber;
   int16_t gold;
};

}

DeclareGameEvent(dota_roshan_kill);

}
