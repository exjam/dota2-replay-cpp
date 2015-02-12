#pragma once
#include <cstdint>
#include "event.h"

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
