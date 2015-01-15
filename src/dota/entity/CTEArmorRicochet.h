#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CTEMetalSparks.h"

namespace dota
{

struct CTEArmorRicochet : public CTEMetalSparks
{
};

DeclareNetworkClass(CTEArmorRicochet);

}
