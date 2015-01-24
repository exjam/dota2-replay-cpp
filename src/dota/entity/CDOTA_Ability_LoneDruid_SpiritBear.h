#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CDOTABaseAbility.h"

namespace dota
{

struct CDOTA_Ability_LoneDruid_SpiritBear : public CDOTABaseAbility
{
   uint32_t m_hBear;
};

DeclareClientClass(CDOTA_Ability_LoneDruid_SpiritBear);

}
