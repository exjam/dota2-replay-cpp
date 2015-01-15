#pragma once
#include <cstdint>
#include "networkclass.h"
#include <string>
#include "CDOTA_BaseNPC_Additive.h"

namespace dota
{

struct CDOTA_Unit_LoopingSound : public CDOTA_BaseNPC_Additive
{
   std::string m_pszNetworkedSoundLoop;
   uint32_t m_nLoopingSoundParity;
};

DeclareNetworkClass(CDOTA_Unit_LoopingSound);

}
