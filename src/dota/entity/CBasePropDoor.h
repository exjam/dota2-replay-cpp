#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDynamicProp.h"

namespace dota
{

struct CBasePropDoor : public CDynamicProp
{
};

DeclareNetworkClass(CBasePropDoor);

}
