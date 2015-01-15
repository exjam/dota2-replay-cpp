#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTA_BaseNPC_Additive.h"

namespace dota
{

struct CDOTA_Unit_Roshan_Halloween : public CDOTA_BaseNPC_Additive
{
   uint32_t m_hChosenTarget;
   uint32_t m_iHealth;
   uint32_t m_iMaxHealth;
};

DeclareNetworkClass(CDOTA_Unit_Roshan_Halloween);

}
