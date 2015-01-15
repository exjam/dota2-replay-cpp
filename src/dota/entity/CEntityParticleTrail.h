#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseParticleEntity.h"

namespace dota
{

struct DT_EntityParticleTrailInfo
{
   float m_flLifetime;
   float m_flStartSize;
   float m_flEndSize;
};

struct CEntityParticleTrail : public CBaseParticleEntity
{
   uint32_t m_iMaterialName;
   DT_EntityParticleTrailInfo m_Info;
   uint32_t m_hConstraintEntity;
};

DeclareNetworkStruct(DT_EntityParticleTrailInfo);
DeclareNetworkClass(CEntityParticleTrail);

}
