#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector3f.h"

namespace dota
{

struct CLightGlow
{
   uint32_t m_clrRender;
   uint32_t m_nHorizontalSize;
   uint32_t m_nVerticalSize;
   uint32_t m_nMinDist;
   uint32_t m_nMaxDist;
   uint32_t m_nOuterMaxDist;
   uint32_t m_spawnflags;
   Vector3f m_vecOrigin;
   Vector3f m_angRotation;
   uint32_t moveparent;
   float m_flGlowProxySize;
   float HDRColorScale;
};

DeclareClientClass(CLightGlow);

}
