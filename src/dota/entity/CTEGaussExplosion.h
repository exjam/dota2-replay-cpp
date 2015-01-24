#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector3f.h"
#include "CTEParticleSystem.h"

namespace dota
{

struct CTEGaussExplosion : public CTEParticleSystem
{
   uint32_t m_nType;
   Vector3f m_vecDirection;
};

DeclareClientClass(CTEGaussExplosion);

}
