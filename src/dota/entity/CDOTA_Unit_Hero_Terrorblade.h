#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTA_BaseNPC_Hero.h"

namespace dota
{

struct CDOTA_Unit_Hero_Terrorblade : public CDOTA_BaseNPC_Hero
{
   int32_t m_nArcanaColor;
};

DeclareNetworkClass(CDOTA_Unit_Hero_Terrorblade);

}
