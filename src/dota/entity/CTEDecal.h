#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector3f.h"
#include "CBaseTempEntity.h"

namespace dota
{

struct CTEDecal : public CBaseTempEntity
{
   Vector3f m_vecOrigin;
   Vector3f m_vecStart;
   uint32_t m_nEntity;
   uint32_t m_nHitbox;
   uint32_t m_nIndex;
};

DeclareClientClass(CTEDecal);

}
