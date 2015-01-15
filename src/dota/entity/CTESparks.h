#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector3f.h"
#include "CTEParticleSystem.h"

namespace dota
{

struct CTESparks : public CTEParticleSystem
{
   uint32_t m_nMagnitude;
   uint32_t m_nTrailLength;
   Vector3f m_vecDir;
};

DeclareNetworkClass(CTESparks);

}
