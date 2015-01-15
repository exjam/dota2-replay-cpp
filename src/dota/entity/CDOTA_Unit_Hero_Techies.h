#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTA_BaseNPC_Hero.h"

namespace dota
{

struct CDOTA_Unit_Hero_Techies : public CDOTA_BaseNPC_Hero
{
   uint32_t m_bHasArcana;
   int32_t m_nArcanaColor;
};

DeclareNetworkClass(CDOTA_Unit_Hero_Techies);

}
