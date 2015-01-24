#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CDOTA_BaseNPC_Creep.h"

namespace dota
{

struct CDOTA_BaseNPC_Creep_Lane : public CDOTA_BaseNPC_Creep
{
   uint32_t m_iHealthPercentage;
};

DeclareClientClass(CDOTA_BaseNPC_Creep_Lane);

}
