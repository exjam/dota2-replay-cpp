#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector3f.h"
#include "CBaseTempEntity.h"

namespace dota
{

struct CTEImpact : public CBaseTempEntity
{
   Vector3f m_vecOrigin;
   Vector3f m_vecNormal;
   uint32_t m_iType;
};

DeclareNetworkClass(CTEImpact);

}
