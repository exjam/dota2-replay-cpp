#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTA_BaseNPC_Additive.h"

namespace dota
{

struct CDOTA_NPC_WitchDoctor_Ward : public CDOTA_BaseNPC_Additive
{
   int32_t m_nTargetType;
};

DeclareNetworkClass(CDOTA_NPC_WitchDoctor_Ward);

}
