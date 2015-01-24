#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector3f.h"
#include "CBaseCombatCharacter.h"

namespace dota
{

struct CBaseGrenade : public CBaseCombatCharacter
{
   float m_flDamage;
   float m_DmgRadius;
   uint32_t m_bIsLive;
   uint32_t m_hThrower;
   Vector3f m_vecVelocity;
   uint32_t m_fFlags;
};

DeclareClientClass(CBaseGrenade);

}
