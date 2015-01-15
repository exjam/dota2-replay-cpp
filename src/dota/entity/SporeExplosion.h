#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseParticleEntity.h"

namespace dota
{

struct SporeExplosion : public CBaseParticleEntity
{
   float m_flSpawnRate;
   float m_flParticleLifetime;
   float m_flStartSize;
   float m_flEndSize;
   float m_flSpawnRadius;
   uint32_t m_bEmit;
   uint32_t m_bDontRemove;
};

DeclareNetworkClass(SporeExplosion);

}
