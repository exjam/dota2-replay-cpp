#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector3f.h"
#include "CBaseEntity.h"

namespace dota
{

struct CBreakableSurface : public CBaseEntity
{
   uint32_t m_nNumWide;
   uint32_t m_nNumHigh;
   float m_flPanelWidth;
   float m_flPanelHeight;
   Vector3f m_vNormal;
   Vector3f m_vCorner;
   uint32_t m_bIsBroken;
   uint32_t m_nSurfaceType;
   uint32_t m_RawPanelBitVec[256];
};

DeclareClientClass(CBreakableSurface);

}
