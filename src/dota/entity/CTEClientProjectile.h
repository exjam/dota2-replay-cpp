#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector3f.h"
#include "CBaseTempEntity.h"

namespace dota
{

struct CTEClientProjectile : public CBaseTempEntity
{
   Vector3f m_vecOrigin;
   Vector3f m_vecVelocity;
   int32_t m_nModelIndex;
   uint32_t m_nLifeTime;
   uint32_t m_hOwner;
};

DeclareNetworkClass(CTEClientProjectile);

}
