#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector3f.h"

namespace dota
{

struct CSun
{
   uint32_t m_clrRender;
   uint32_t m_clrOverlay;
   Vector3f m_vDirection;
   uint32_t m_bOn;
   uint32_t m_nSize;
   uint32_t m_nOverlaySize;
   uint32_t m_nMaterial;
   uint32_t m_nOverlayMaterial;
   float HDRColorScale;
};

DeclareClientClass(CSun);

}
