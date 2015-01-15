#pragma once
#include <cstdint>
#include "networkclass.h"

namespace dota
{

struct DT_RadiantData
{
   uint32_t m_iReliableGoldRadiant[10];
   uint32_t m_iUnreliableGoldRadiant[10];
   uint64_t m_bWorldTreeStateRadiant[128];
};

struct DT_EndScoreAndSpectatorStats
{
   uint32_t m_iTotalEarnedGold[10];
   uint32_t m_iTotalEarnedXP[10];
   uint64_t m_bWorldTreeStateSpectator[64];
};

struct DT_DireData
{
   uint32_t m_iReliableGoldDire[10];
   uint32_t m_iUnreliableGoldDire[10];
   uint64_t m_bWorldTreeStateDire[128];
};

struct CDOTA_PlayerResource
{
   std::string m_iszPlayerNames[32];
   std::string m_iszSelectedHero[10];
   int32_t m_nSelectedHeroID[10];
   uint32_t m_iPlayerTeams[32];
   uint32_t m_iKills[10];
   uint32_t m_iAssists[10];
   uint32_t m_iDeaths[10];
   uint32_t m_iStreak[10];
   int32_t m_iRespawnSeconds[10];
   int32_t m_iLastBuybackTime[10];
   uint32_t m_iLevel[10];
   uint32_t m_iDenyCount[10];
   uint32_t m_iLastHitCount[10];
   uint32_t m_iLastHitStreak[10];
   uint32_t m_iLastHitMultikill[10];
   uint32_t m_iNearbyCreepDeathCount[10];
   uint32_t m_hSelectedHero[10];
   uint32_t m_bFullyJoinedServer[32];
   uint32_t m_bFakeClient[32];
   int64_t m_iPlayerSteamIDs[32];
   uint32_t m_bIsBroadcaster[32];
   uint32_t m_iBroadcasterChannel[32];
   uint32_t m_iBroadcasterChannelSlot[32];
   std::string m_iszBroadcasterChannelDescription[6];
   std::string m_iszBroadcasterChannelCountryCode[6];
   std::string m_iszBroadcasterChannelLanguageCode[6];
   uint32_t m_iConnectionState[32];
   uint32_t m_bAFK[10];
   uint32_t m_bVoiceChatBanned[10];
   uint32_t m_iTimedRewardDrops[10];
   uint32_t m_iTimedRewardCrates[10];
   int32_t m_nPossibleHeroSelection[10];
   int32_t m_nSuggestedHeroes[20];
   int32_t m_iMetaLevel[10];
   int32_t m_iMetaExperience[10];
   int32_t m_iMetaExperienceAwarded[10];
   uint32_t m_bHasRepicked[10];
   uint32_t m_bHasRandomed[10];
   uint32_t m_UnitShareMasks[10];
   uint32_t m_bBattleBonusActive[10];
   int32_t m_iBattleBonusRate[10];
   float m_flBuybackCooldownTime[10];
   float m_flBuybackGoldLimitTime[10];
   float m_flBuybackCostTime[10];
   uint32_t m_iCustomBuybackCost[10];
   float m_flCustomBuybackCooldown[10];
   uint32_t m_iGoldBagsCollected[10];
   float m_fStuns[10];
   float m_fHealing[10];
   int32_t m_iTowerKills[10];
   int32_t m_iRoshanKills[10];
   int32_t m_iEventPoints[10];
   int32_t m_iEventPremiumPoints[10];
   uint32_t m_hCameraTarget[10];
   int32_t m_iEventRanks[10];
   uint32_t m_unCompendiumLevel[10];
   uint32_t m_bIsBroadcasterChannelCameraman[32];
   uint32_t m_bHasPredictedVictory[10];
   uint32_t m_bReservedHeroOnly[10];
   uint32_t m_bQualifiesForPAContractReward[10];
   uint32_t m_iTimedRewardEvents[10];
   DT_EndScoreAndSpectatorStats EndScoreAndSpectatorStats;
   DT_RadiantData RadiantOnlyData;
   DT_DireData DireOnlyData;
};

DeclareNetworkStruct(DT_RadiantData);
DeclareNetworkStruct(DT_EndScoreAndSpectatorStats);
DeclareNetworkStruct(DT_DireData);
DeclareNetworkClass(CDOTA_PlayerResource);

}
