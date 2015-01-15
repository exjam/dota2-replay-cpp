#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector3f.h"
#include "CBaseTempEntity.h"

namespace dota
{

struct CTEBubbleTrail : public CBaseTempEntity
{
   Vector3f m_vecMins;
   Vector3f m_vecMaxs;
   int32_t m_nModelIndex;
   float m_flWaterZ;
   uint32_t m_nCount;
   float m_fSpeed;
};

DeclareNetworkClass(CTEBubbleTrail);

}
