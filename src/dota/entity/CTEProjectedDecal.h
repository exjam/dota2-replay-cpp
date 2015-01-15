#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector3f.h"
#include "CBaseTempEntity.h"

namespace dota
{

struct CTEProjectedDecal : public CBaseTempEntity
{
   Vector3f m_vecOrigin;
   Vector3f m_angRotation;
   float m_flDistance;
   uint32_t m_nIndex;
};

DeclareNetworkClass(CTEProjectedDecal);

}
