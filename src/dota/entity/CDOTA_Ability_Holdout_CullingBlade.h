#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTA_Ability_Axe_CullingBlade.h"

namespace dota
{

struct CDOTA_Ability_Holdout_CullingBlade : public CDOTA_Ability_Axe_CullingBlade
{
};

DeclareNetworkClass(CDOTA_Ability_Holdout_CullingBlade);

}
