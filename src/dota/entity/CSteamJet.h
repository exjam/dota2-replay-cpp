#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseParticleEntity.h"

namespace dota
{

struct CSteamJet : public CBaseParticleEntity
{
   float m_SpreadSpeed;
   float m_Speed;
   float m_StartSize;
   float m_EndSize;
   float m_Rate;
   float m_JetLength;
   uint32_t m_bEmit;
   uint32_t m_bFaceLeft;
   uint32_t m_nType;
   uint32_t m_spawnflags;
   float m_flRollSpeed;
};

DeclareNetworkClass(CSteamJet);

}
