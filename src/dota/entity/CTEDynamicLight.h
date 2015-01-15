#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector3f.h"
#include "CBaseTempEntity.h"

namespace dota
{

struct CTEDynamicLight : public CBaseTempEntity
{
   Vector3f m_vecOrigin;
   uint32_t r;
   uint32_t g;
   uint32_t b;
   int32_t exponent;
   float m_fRadius;
   float m_fTime;
   float m_fDecay;
};

DeclareNetworkClass(CTEDynamicLight);

}
