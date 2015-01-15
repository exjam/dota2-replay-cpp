#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector3f.h"
#include "CBaseTempEntity.h"

namespace dota
{

struct CTEDOTAProjectileLoc : public CBaseTempEntity
{
   uint32_t m_iMoveSpeed;
   Vector3f m_vSourceLoc;
   Vector3f m_vTargetLoc;
   uint32_t m_hTarget;
   uint32_t m_iParticleSystem;
   uint32_t m_bDodgeable;
   uint32_t m_bIsAttack;
   uint32_t m_bIsEvaded;
   float m_flExpireTime;
};

DeclareNetworkClass(CTEDOTAProjectileLoc);

}
