#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTA_BaseNPC_Creep.h"

namespace dota
{

struct CDOTA_BaseNPC_Creep_Lane : public CDOTA_BaseNPC_Creep
{
   uint32_t m_iHealthPercentage;
};

DeclareNetworkClass(CDOTA_BaseNPC_Creep_Lane);

}
