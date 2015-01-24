#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseParticleEntity.h"

namespace dota
{

struct ParticleSmokeGrenade : public CBaseParticleEntity
{
   float m_flSpawnTime;
   float m_FadeStartTime;
   float m_FadeEndTime;
   uint32_t m_CurrentStage;
};

DeclareClientClass(ParticleSmokeGrenade);

}
