#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector3f.h"
#include "CBaseEntity.h"

namespace dota
{

struct CFunc_Dust
{
   uint32_t m_Color;
   uint32_t m_SpawnRate;
   uint32_t m_SpeedMax;
   float m_flSizeMin;
   float m_flSizeMax;
   uint32_t m_DistMax;
   uint32_t m_LifetimeMin;
   uint32_t m_LifetimeMax;
   uint32_t m_DustFlags;
   int32_t m_nModelIndex;
   float m_FallSpeed;
   DT_CollisionProperty m_Collision;
};

DeclareNetworkClass(CFunc_Dust);

}
