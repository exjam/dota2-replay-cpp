#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTA_BaseNPC_Additive.h"

namespace dota
{

struct CDOTA_BaseNPC_Hero : public CDOTA_BaseNPC_Additive
{
   int32_t m_iCurrentXP;
   float m_flRespawnTime;
   float m_flRespawnTimePenalty;
   int32_t m_iAbilityPoints;
   float m_flStrength;
   float m_flAgility;
   float m_flIntellect;
   float m_flStrengthTotal;
   float m_flAgilityTotal;
   float m_flIntellectTotal;
   int32_t m_iRecentDamage;
   int32_t m_iPlayerID;
   uint32_t m_bReincarnating;
   float m_flSpawnedAt;
   uint32_t m_hReplicatingOtherHeroModel;
   uint32_t m_hEconConsumableAbility;
   uint32_t m_bCustomKillEffect;
};

DeclareNetworkClass(CDOTA_BaseNPC_Hero);

}
