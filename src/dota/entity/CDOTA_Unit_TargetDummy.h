#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTA_BaseNPC_Additive.h"

namespace dota
{

struct CDOTA_Unit_TargetDummy : public CDOTA_BaseNPC_Additive
{
   float m_flDamageTaken;
   float m_flStartDamageTime;
   float m_flLastDamageTime;
   float m_flLastHit;
};

DeclareNetworkClass(CDOTA_Unit_TargetDummy);

}
