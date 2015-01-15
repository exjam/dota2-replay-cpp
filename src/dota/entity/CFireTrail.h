#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseParticleEntity.h"

namespace dota
{

struct CFireTrail : public CBaseParticleEntity
{
   int32_t m_nAttachment;
   float m_flLifetime;
};

DeclareNetworkClass(CFireTrail);

}
