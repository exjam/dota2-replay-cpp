#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CDOTA_BaseNPC_Creep.h"

namespace dota
{

struct CDOTA_BaseNPC_Creep_LootGreevil : public CDOTA_BaseNPC_Creep
{
   uint32_t m_bIsRareLootGreevil;
};

DeclareClientClass(CDOTA_BaseNPC_Creep_LootGreevil);

}
