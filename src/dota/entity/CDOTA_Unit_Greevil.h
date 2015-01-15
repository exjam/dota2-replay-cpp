#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTA_BaseNPC_Additive.h"

namespace dota
{

struct CDOTA_Unit_Greevil : public CDOTA_BaseNPC_Additive
{
   float m_flRespawnTime;
};

DeclareNetworkClass(CDOTA_Unit_Greevil);

}
