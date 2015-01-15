#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTABaseAbility.h"

namespace dota
{

struct CDOTA_Ability_LoneDruid_SpiritBear : public CDOTABaseAbility
{
   uint32_t m_hBear;
};

DeclareNetworkClass(CDOTA_Ability_LoneDruid_SpiritBear);

}
