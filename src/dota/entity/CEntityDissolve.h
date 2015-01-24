#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector3f.h"
#include "CBaseEntity.h"

namespace dota
{

struct CEntityDissolve : public CBaseEntity
{
   float m_flStartTime;
   float m_flFadeInStart;
   float m_flFadeInLength;
   float m_flFadeOutModelStart;
   float m_flFadeOutModelLength;
   float m_flFadeOutStart;
   float m_flFadeOutLength;
   uint32_t m_nDissolveType;
   Vector3f m_vDissolverOrigin;
   uint32_t m_nMagnitude;
};

DeclareClientClass(CEntityDissolve);

}
