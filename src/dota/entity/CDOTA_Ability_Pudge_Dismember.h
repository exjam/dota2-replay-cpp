#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTABaseAbility.h"

namespace dota
{

struct CDOTA_Ability_Pudge_Dismember : public CDOTABaseAbility
{
   uint32_t m_hVictim;
};

DeclareNetworkClass(CDOTA_Ability_Pudge_Dismember);

}
