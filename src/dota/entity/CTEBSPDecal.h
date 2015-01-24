#pragma once
#include <cstdint>
#include "clientclass.h"
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

DeclareClientClass(CTEBSPDecal);

}
