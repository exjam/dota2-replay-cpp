#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct dota_match_done
{
   uint8_t winningteam;
};

}

DeclareGameEvent(dota_match_done);

}
