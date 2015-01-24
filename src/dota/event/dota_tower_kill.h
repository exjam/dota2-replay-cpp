#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct dota_tower_kill
{
   int16_t killer_userid;
   int16_t teamnumber;
   int16_t gold;
};

}

DeclareGameEvent(dota_tower_kill);

}
