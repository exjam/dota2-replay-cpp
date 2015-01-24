#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CDOTABaseAbility : public CBaseEntity
{
   uint32_t m_bHidden;
   uint32_t m_bActivated;
   uint32_t m_iDirtyButtons;
   uint32_t m_iLevel;
   uint32_t m_bToggleState;
   uint32_t m_bInAbilityPhase;
   float m_fCooldown;
   uint32_t m_iCastRange;
   float m_flCooldownLength;
   uint32_t m_iManaCost;
   uint32_t m_bAutoCastState;
   float m_flChannelStartTime;
   float m_flOverrideCastPoint;
   uint32_t m_bInIndefiniteCooldown;
};

DeclareClientClass(CDOTABaseAbility);

}
