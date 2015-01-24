#pragma once
#include <cstdint>
#include "gameevent.h"

namespace dota
{

namespace event
{

struct hltv_versioninfo
{
   uint8_t version;
};

}

DeclareGameEvent(hltv_versioninfo);

}
