#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector2f.h"
#include "vector3f.h"
#include "NextBotCombatCharacter.h"

namespace dota
{

struct DT_DOTA_UnitInventory
{
   uint32_t m_hItems[14];
   uint32_t m_iParity;
   uint32_t m_hInventoryParent;
   uint32_t m_bStashEnabled;
   uint32_t m_hTransientCastItem;
};

struct DT_DOTA_ModifierManager
{
   uint32_t m_hModifierParent;
};

struct CDOTA_BaseNPC : public NextBotCombatCharacter
{
   uint32_t m_iCurrentLevel;
   int32_t m_iCustomXPValue;
   uint32_t m_iIsControllableByPlayer;
   uint32_t m_bIsPhantom;
   uint32_t m_bIsAncient;
   uint32_t m_bStolenScepter;
   uint32_t m_bIsNeutralUnitType;
   uint32_t m_bIsSummoned;
   uint32_t m_bCanBeDominated;
   uint32_t m_bHasUpgradeableAbilities;
   int32_t m_iBKBChargesUsed;
   int32_t m_iHealth;
   float m_flHealthThinkRegen;
   uint32_t m_iMaxHealth;
   uint32_t m_iAttackCapabilities;
   uint32_t m_iDayTimeVisionRange;
   uint32_t m_iNightTimeVisionRange;
   float m_flMana;
   float m_flMaxMana;
   float m_flManaThinkRegen;
   uint32_t m_hAbilities[16];
   int32_t m_iUnitNameIndex;
   uint32_t m_iDamageMin;
   uint32_t m_iDamageMax;
   int32_t m_iDamageBonus;
   uint32_t m_lifeState;
   DT_DOTA_ModifierManager m_ModifierManager;
   DT_DOTA_UnitInventory m_Inventory;
   uint32_t m_nUnitState;
   uint32_t m_iTaggedAsVisibleByTeam;
   uint32_t m_iCurShop;
   int32_t m_anglediff;
   uint32_t m_fFlags;
   Vector3f m_vecOrigin;
   uint32_t m_cellX;
   uint32_t m_cellY;
   uint32_t m_cellZ;
   Vector2f m_angRotation;
   int32_t m_NetworkActivity;
   int32_t m_NetworkSequenceIndex;
   int32_t m_iBotDebugData;
   uint32_t m_hMyWearables[20];
   uint32_t m_bShouldDoFlyHeightVisual;
   int64_t m_nTotalDamageTaken;
};

DeclareClientStruct(DT_DOTA_UnitInventory);
DeclareClientStruct(DT_DOTA_ModifierManager);
DeclareClientClass(CDOTA_BaseNPC);

}
