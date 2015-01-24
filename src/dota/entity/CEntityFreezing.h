#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector3f.h"
#include "CBaseEntity.h"

namespace dota
{

struct CEntityFreezing : public CBaseEntity
{
   Vector3f m_vFreezingOrigin;
   float m_flFrozenPerHitbox[50];
   float m_flFrozen;
   uint32_t m_bFinishFreezing;
};

DeclareClientClass(CEntityFreezing);

}
