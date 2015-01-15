#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector2f.h"
#include "vector3f.h"
#include "CBaseTempEntity.h"

namespace dota
{

struct CTEPhysicsProp : public CBaseTempEntity
{
   Vector3f m_vecOrigin;
   Vector3f m_angRotation;
   Vector3f m_vecVelocity;
   int32_t m_nModelIndex;
   int32_t m_nSkin;
   uint32_t m_nFlags;
   uint32_t m_nEffects;
};

DeclareNetworkClass(CTEPhysicsProp);

}
