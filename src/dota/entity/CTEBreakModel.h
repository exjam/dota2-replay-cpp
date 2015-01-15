#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector2f.h"
#include "vector3f.h"
#include "CBaseTempEntity.h"

namespace dota
{

struct CTEBreakModel : public CBaseTempEntity
{
   Vector3f m_vecOrigin;
   Vector3f m_angRotation;
   Vector3f m_vecSize;
   Vector3f m_vecVelocity;
   int32_t m_nModelIndex;
   uint32_t m_nRandomization;
   uint32_t m_nCount;
   float m_fTime;
   uint32_t m_nFlags;
};

DeclareNetworkClass(CTEBreakModel);

}
