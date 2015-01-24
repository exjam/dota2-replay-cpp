#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector3f.h"
#include "CTEParticleSystem.h"

namespace dota
{

struct CTEExplosion : public CTEParticleSystem
{
   int32_t m_nModelIndex;
   float m_fScale;
   uint32_t m_nFrameRate;
   uint32_t m_nFlags;
   Vector3f m_vecNormal;
   uint32_t m_chMaterialType;
   uint32_t m_nRadius;
   uint32_t m_nMagnitude;
};

DeclareClientClass(CTEExplosion);

}
