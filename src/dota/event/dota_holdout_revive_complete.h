#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct dota_holdout_revive_complete
{
   int16_t caster;
   int16_t target;
};

}

DeclareGameEvent(dota_holdout_revive_complete);

}
