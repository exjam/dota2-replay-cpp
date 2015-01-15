#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTA_BaseNPC_HoldoutTower.h"

namespace dota
{

struct CDOTA_BaseNPC_HoldoutTower_ReduceSpeed : public CDOTA_BaseNPC_HoldoutTower
{
};

DeclareNetworkClass(CDOTA_BaseNPC_HoldoutTower_ReduceSpeed);

}
