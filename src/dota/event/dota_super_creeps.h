#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct dota_super_creeps
{
   int16_t teamnumber;
};

}

DeclareGameEvent(dota_super_creeps);

}
