#pragma once
#include <cstdint>
#include "networkclass.h"
#include <string>
#include "CDOTABaseAbility.h"

namespace dota
{

struct CDOTA_Ability_Rubick_SpellSteal : public CDOTABaseAbility
{
   std::string m_ActivityModifier;
   float m_fStolenCastPoint;
};

DeclareNetworkClass(CDOTA_Ability_Rubick_SpellSteal);

}
