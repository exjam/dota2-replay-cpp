#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBasePropDoor.h"

namespace dota
{

struct CPropDoorRotating : public CBasePropDoor
{
};

DeclareNetworkClass(CPropDoorRotating);

}
