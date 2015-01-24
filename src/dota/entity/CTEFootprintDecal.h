#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector3f.h"
#include "CBaseTempEntity.h"

namespace dota
{

struct CTEFootprintDecal : public CBaseTempEntity
{
   Vector3f m_vecOrigin;
   Vector3f m_vecDirection;
   uint32_t m_nEntity;
   uint32_t m_nIndex;
   uint32_t m_chMaterialType;
};

DeclareClientClass(CTEFootprintDecal);

}
