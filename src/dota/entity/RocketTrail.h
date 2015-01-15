#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector3f.h"
#include "CBaseParticleEntity.h"

namespace dota
{

struct RocketTrail : public CBaseParticleEntity
{
   float m_SpawnRate;
   Vector3f m_StartColor;
   Vector3f m_EndColor;
   float m_ParticleLifetime;
   float m_StopEmitTime;
   float m_MinSpeed;
   float m_MaxSpeed;
   float m_StartSize;
   float m_EndSize;
   float m_SpawnRadius;
   uint32_t m_bEmit;
   int32_t m_nAttachment;
   float m_Opacity;
   uint32_t m_bDamaged;
   float m_flFlareScale;
};

DeclareNetworkClass(RocketTrail);

}
