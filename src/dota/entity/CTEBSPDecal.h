#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector3f.h"
#include "CBaseTempEntity.h"

namespace dota
{

struct CTEBSPDecal : public CBaseTempEntity
{
   Vector3f m_vecOrigin;
   uint32_t m_nEntity;
   uint32_t m_nIndex;
};

DeclareNetworkClass(CTEBSPDecal);

}
