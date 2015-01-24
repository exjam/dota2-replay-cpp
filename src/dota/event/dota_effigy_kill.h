#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct dota_effigy_kill
{
   int16_t owner_userid;
};

}

DeclareGameEvent(dota_effigy_kill);

}
