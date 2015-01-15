#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector3f.h"
#include "CBaseTempEntity.h"

namespace dota
{

struct CTESprite : public CBaseTempEntity
{
   Vector3f m_vecOrigin;
   int32_t m_nModelIndex;
   float m_fScale;
   uint32_t m_nBrightness;
};

DeclareNetworkClass(CTESprite);

}
