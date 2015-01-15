#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTA_BaseNPC_Hero.h"

namespace dota
{

struct CDOTA_Unit_Hero_Meepo : public CDOTA_BaseNPC_Hero
{
   int32_t m_nWhichMeepo;
   uint32_t m_bIsIllusion;
};

DeclareNetworkClass(CDOTA_Unit_Hero_Meepo);

}
