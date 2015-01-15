#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTA_BaseNPC_Additive.h"

namespace dota
{

struct CDOTA_Unit_Courier : public CDOTA_BaseNPC_Additive
{
   float m_flRespawnTime;
   uint32_t m_nCourierState;
   uint32_t m_hCourierStateEntity;
   uint32_t m_bFlyingCourier;
   int32_t m_iUnusualColor;
   int32_t m_iUnusualParticleSystem;
   uint32_t m_hCourierWearable;
   uint32_t m_bMorphEnabled;
};

DeclareNetworkClass(CDOTA_Unit_Courier);

}
