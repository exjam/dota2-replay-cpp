#pragma once
#include <cstdint>
#include "event.h"

namespace dota
{

namespace event
{

struct hltv_fixed
{
   int32_t posx;
   int32_t posy;
   int32_t posz;
   int16_t theta;
   int16_t phi;
   int16_t offset;
   float fov;
   int16_t target;
};

}

DeclareGameEvent(hltv_fixed);

}
