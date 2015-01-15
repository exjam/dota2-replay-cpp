#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector3f.h"
#include "CBaseTempEntity.h"

namespace dota
{

struct CTEShatterSurface : public CBaseTempEntity
{
   Vector3f m_vecOrigin;
   Vector3f m_vecAngles;
   Vector3f m_vecForce;
   Vector3f m_vecForcePos;
   float m_flWidth;
   float m_flHeight;
   float m_flShardSize;
   uint32_t m_nSurfaceType;
   uint32_t m_uchFrontColor[3];
   uint32_t m_uchBackColor[3];
};

DeclareNetworkClass(CTEShatterSurface);

}
