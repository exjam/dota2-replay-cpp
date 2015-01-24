#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CDOTABaseAbility.h"

namespace dota
{

struct CDOTA_Ability_Brewmaster_PrimalSplit : public CDOTABaseAbility
{
   uint32_t m_hPrimary;
   uint32_t m_hSecondary;
   uint32_t m_hTertiary;
};

DeclareClientClass(CDOTA_Ability_Brewmaster_PrimalSplit);

}
