#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector3f.h"
#include "CBaseTempEntity.h"

namespace dota
{

struct CTESpriteSpray : public CBaseTempEntity
{
   Vector3f m_vecOrigin;
   Vector3f m_vecDirection;
   int32_t m_nModelIndex;
   float m_fNoise;
   uint32_t m_nSpeed;
   uint32_t m_nCount;
};

DeclareClientClass(CTESpriteSpray);

}
