#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseCombatCharacter.h"

namespace dota
{

struct CAI_BaseNPC : public CBaseCombatCharacter
{
   uint32_t m_lifeState;
   uint32_t m_bPerformAvoidance;
   uint32_t m_bIsMoving;
   uint32_t m_bFadeCorpse;
   int32_t m_iDeathPose;
   int32_t m_iDeathFrame;
   uint32_t m_bSpeedModActive;
   int32_t m_iSpeedModRadius;
   int32_t m_iSpeedModSpeed;
   uint32_t m_bImportanRagdoll;
   float m_flTimePingEffect;
};

DeclareNetworkClass(CAI_BaseNPC);

}
