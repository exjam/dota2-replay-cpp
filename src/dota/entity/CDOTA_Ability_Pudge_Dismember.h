#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CDOTABaseAbility.h"

namespace dota
{

struct CDOTA_Ability_Pudge_Dismember : public CDOTABaseAbility
{
   uint32_t m_hVictim;
};

DeclareClientClass(CDOTA_Ability_Pudge_Dismember);

}
