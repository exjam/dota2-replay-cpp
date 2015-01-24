#pragma once
#include <cstdint>
#include "clientclass.h"

namespace dota
{

struct CDOTABaseGameMode
{
   uint32_t m_bAlwaysShowPlayerInventory;
   uint32_t m_bGoldSoundDisabled;
   uint32_t m_bRecommendedItemsDisabled;
   uint32_t m_bFogOfWarDisabled;
   uint32_t m_bUseCustomBuybackCost;
   uint32_t m_bUseCustomBuybackCooldown;
   uint32_t m_bBuybackEnabled;
   float m_flCameraDistanceOverride;
   uint32_t m_hOverrideSelectionEntity;
   uint32_t m_bTopBarTeamValuesOverride;
   uint32_t m_bTopBarTeamValuesVisible;
   int32_t m_nTeamGoodGuysTopBarValue;
   int32_t m_nTeamBadGuysTopBarValue;
   uint32_t m_bUseCustomHeroLevels;
   int32_t m_nCustomHeroMaxLevel;
   uint32_t m_nCustomXPRequiredToReachNextLevel[99];
};

DeclareClientClass(CDOTABaseGameMode);

}
