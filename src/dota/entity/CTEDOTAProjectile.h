#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseTempEntity.h"

namespace dota
{

struct CTEDOTAProjectile : public CBaseTempEntity
{
   uint32_t m_iMoveSpeed;
   uint32_t m_hSource;
   uint32_t m_hTarget;
   uint32_t m_iSourceAttachment;
   uint32_t m_iParticleSystem;
   uint32_t m_bDodgeable;
   uint32_t m_bIsAttack;
   uint32_t m_bIsEvaded;
   float m_flExpireTime;
};

DeclareNetworkClass(CTEDOTAProjectile);

}
