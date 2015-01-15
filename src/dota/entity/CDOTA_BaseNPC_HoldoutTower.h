#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTA_BaseNPC_Tower.h"

namespace dota
{

struct CDOTA_BaseNPC_HoldoutTower : public CDOTA_BaseNPC_Tower
{
};

DeclareNetworkClass(CDOTA_BaseNPC_HoldoutTower);

}
