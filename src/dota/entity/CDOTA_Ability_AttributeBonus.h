#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTABaseAbility.h"

namespace dota
{

struct CDOTA_Ability_AttributeBonus : public CDOTABaseAbility
{
};

DeclareNetworkClass(CDOTA_Ability_AttributeBonus);

}
