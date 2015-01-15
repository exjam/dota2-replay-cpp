#pragma once
#include <cstdint>
#include "networkclass.h"
#include <string>
#include "CBaseParticleEntity.h"

namespace dota
{

struct CFuncSmokeVolume : public CBaseParticleEntity
{
   uint32_t m_Color1;
   uint32_t m_Color2;
   std::string m_MaterialName;
   float m_ParticleDrawWidth;
   float m_ParticleSpacingDistance;
   float m_DensityRampSpeed;
   float m_RotationSpeed;
   float m_MovementSpeed;
   float m_Density;
   float m_maxDrawDistance;
   uint32_t m_spawnflags;
};

DeclareNetworkClass(CFuncSmokeVolume);

}
