#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CDOTA_BaseNPC_Hero.h"

namespace dota
{

struct CDOTA_Unit_Hero_Terrorblade : public CDOTA_BaseNPC_Hero
{
   int32_t m_nArcanaColor;
};

DeclareClientClass(CDOTA_Unit_Hero_Terrorblade);

}
