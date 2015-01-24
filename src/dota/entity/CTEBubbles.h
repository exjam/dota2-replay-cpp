#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector3f.h"
#include "CBaseTempEntity.h"

namespace dota
{

struct CTEBubbles : public CBaseTempEntity
{
   Vector3f m_vecMins;
   Vector3f m_vecMaxs;
   int32_t m_nModelIndex;
   float m_fHeight;
   uint32_t m_nCount;
   float m_fSpeed;
};

DeclareClientClass(CTEBubbles);

}
