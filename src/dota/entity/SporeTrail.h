#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector3f.h"
#include "CBaseParticleEntity.h"

namespace dota
{

struct SporeTrail : public CBaseParticleEntity
{
   float m_flSpawnRate;
   Vector3f m_vecEndColor;
   float m_flParticleLifetime;
   float m_flStartSize;
   float m_flEndSize;
   float m_flSpawnRadius;
   uint32_t m_bEmit;
};

DeclareNetworkClass(SporeTrail);

}
