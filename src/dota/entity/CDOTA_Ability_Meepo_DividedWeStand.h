#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTABaseAbility.h"

namespace dota
{

struct CDOTA_Ability_Meepo_DividedWeStand : public CDOTABaseAbility
{
   uint32_t m_entPrimeDividedWeStand;
   uint32_t m_entNextDividedWeStand;
   int32_t m_nWhichDividedWeStand;
   int32_t m_nNumDividedWeStand;
};

DeclareNetworkClass(CDOTA_Ability_Meepo_DividedWeStand);

}
