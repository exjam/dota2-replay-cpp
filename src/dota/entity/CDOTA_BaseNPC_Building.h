#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector2f.h"
#include "vector3f.h"
#include <string>
#include "CDOTA_BaseNPC.h"

namespace dota
{

struct CDOTA_BaseNPC_Building : public CDOTA_BaseNPC
{
   int32_t m_nFXIndex;
   int32_t m_nFXIndexDestruction;
   Vector2f m_angInitialAngles;
   int32_t m_hHeroStatueSequence;
   float m_fHeroStatueCycle;
   int32_t m_iHeroStatueStatusEffectIndex;
   uint32_t m_bHeroStatue;
   std::string m_HeroStatueInscription;
   int32_t m_iHeroStatueOwnerPlayerID;
};

DeclareNetworkClass(CDOTA_BaseNPC_Building);

}
