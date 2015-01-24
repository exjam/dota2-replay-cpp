#pragma once
#include <cstdint>
#include "clientclass.h"
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

DeclareClientStruct(DT_EntityParticleTrailInfo);
DeclareClientClass(CEntityParticleTrail);

}
