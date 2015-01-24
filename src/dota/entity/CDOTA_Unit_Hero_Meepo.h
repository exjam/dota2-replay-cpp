#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CDOTA_BaseNPC_Hero.h"

namespace dota
{

struct CDOTA_Unit_Hero_Meepo : public CDOTA_BaseNPC_Hero
{
   int32_t m_nWhichMeepo;
   uint32_t m_bIsIllusion;
};

DeclareClientClass(CDOTA_Unit_Hero_Meepo);

}
