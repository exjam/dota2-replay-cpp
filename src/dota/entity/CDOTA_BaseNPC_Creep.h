#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTA_BaseNPC_Additive.h"

namespace dota
{

struct CDOTA_BaseNPC_Creep : public CDOTA_BaseNPC_Additive
{
   uint32_t m_bIsWaitingToSpawn;
};

DeclareNetworkClass(CDOTA_BaseNPC_Creep);

}
