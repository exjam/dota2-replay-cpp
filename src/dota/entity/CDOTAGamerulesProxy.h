#pragma once
#include <cstdint>
#include "networkclass.h"
#include <string>
#include "CGameRulesProxy.h"

namespace dota
{

struct DT_DOTA_ItemStockInfo
{
   uint32_t usItemIndex;
   float fStockDuration;
   float fStockTime;
   int32_t iStockCount;
   int32_t iMaxCount;
};

struct DT_DOTA_AssassinMinigameNetworkState
{
   uint32_t nAssassinState;
   uint32_t nVictimHeroID;
};

struct DT_DOTA_AbilityDraftAbilityState
{
   uint32_t m_unAbilityIndex;
   uint32_t m_unPlayerID;
   uint32_t m_unAbilityPlayerSlot;
};

struct DT_DOTAGamerules
{
   int32_t m_iNetTimeOfDay;
   float m_fGameTime;
   uint32_t m_bGamePaused;
   DT_DOTA_ItemStockInfo m_ItemStockInfoGood[8];
   DT_DOTA_ItemStockInfo m_ItemStockInfoBad[8];
   DT_DOTA_AssassinMinigameNetworkState m_AssassinMiniGameNetData;
   uint32_t m_hGoodGuyFountain;
   uint32_t m_hBadGuyFountain;
   uint32_t m_hGoodGuyShop;
   uint32_t m_hBadGuyShop;
   uint32_t m_hSideShop1;
   uint32_t m_hSideShop2;
   uint32_t m_hSecretShop1;
   uint32_t m_hSecretShop2;
   uint32_t m_hGoodGuyFort;
   uint32_t m_hBadGuyFort;
   uint32_t m_hAnnouncerGood;
   uint32_t m_hAnnouncerBad;
   uint32_t m_hAnnouncerSpectator;
   uint32_t m_hAnnouncerGood_KillingSpree;
   uint32_t m_hAnnouncerBad_KillingSpree;
   uint32_t m_hAnnouncerSpectator_KillingSpree;
   int32_t m_nGameState;
   float m_flStateTransitionTime;
   int32_t m_iGameMode;
   int32_t m_nHeroPickState;
   int32_t m_iCMModePickBanOrder;
   int32_t m_iCDModePickBanOrder;
   float m_flHeroPickStateTransitionTime;
   float m_fExtraTimeRemaining[2];
   uint32_t m_iPlayerIDsInControl[32];
   uint32_t m_bSuggestedGoodHeroes[128];
   uint32_t m_bSuggestedBadHeroes[128];
   int32_t m_iCaptainPlayerIDs[2];
   int32_t m_BannedHeroes[10];
   int32_t m_SelectedHeroes[10];
   int32_t m_AvailableHerosPerPlayer[50];
   int32_t m_UnlockedHeroesPerPlayer[10];
   int32_t m_LockedHeroesPerPlayer[400];
   int32_t m_iActiveTeam;
   int32_t m_iStartingTeam;
   int32_t m_iMiscHeroPickCounter;
   float m_flPreGameStartTime;
   float m_flGameStartTime;
   float m_flGameEndTime;
   float m_flGameLoadTime;
   float m_fGoodGlyphCooldown;
   float m_fBadGlyphCooldown;
   uint32_t m_bIsNightstalkerNight;
   uint32_t m_bIsTemporaryNight;
   int32_t m_nGameWinner;
   int32_t m_nLoadedPlayers;
   int32_t m_nExpectedPlayers;
   int32_t m_iMinimapDebugGridState;
   uint32_t m_iFoWFrameNumber;
   uint32_t m_bIsInItemTestingMode;
   uint32_t m_bIsInCinematicMode;
   uint64_t m_bItemWhiteList[4];
   uint32_t m_hEndGameCinematicEntity;
   uint32_t m_bIsStableMode;
   uint64_t m_unMatchID64;
   int32_t m_BotDebugPushLane[18];
   int32_t m_BotDebugDefendLane[18];
   int32_t m_BotDebugFarmLane[6];
   int32_t m_BotDebugRoam[8];
   uint32_t m_hBotDebugRoamTarget[2];
   int32_t m_BotDebugRoshan[2];
   uint32_t m_lobbyLeagueID;
   std::string m_lobbyGameName;
   uint32_t m_bMatchSignoutComplete;
   uint32_t m_bWhiteListEnabled;
   uint32_t m_bHeroRespawnEnabled;
   int32_t m_nLastHitUIMode;
   uint32_t m_bHUDTimerTutorialMode;
   uint32_t m_unFanfareGoodGuys;
   uint32_t m_unFanfareBadGuys;
   uint32_t m_nSeriesType;
   uint32_t m_nRadiantSeriesWins;
   uint32_t m_nDireSeriesWins;
   uint32_t m_nHalloweenTransitionState;
   float m_flHalloweenRoshanLifetime;
   uint32_t m_bTier3TowerDestroyed;
   int32_t m_iCustomGameScore[2];
   int32_t m_iPauseTeam;
   int32_t m_nGGTeam;
   float m_flGGEndsAtTime;
   uint32_t m_hGameModeEntity;
   int32_t m_nHalloweenRoshanLevel;
   float m_flHalloweenRoshanRoundStartTime;
   int32_t m_nHalloweenRoshanRemainingHealth;
   int32_t m_nCustomGameDifficulty;
   uint32_t m_hOverlayHealthBarUnit;
   int32_t m_nOverlayHealthBarType;
   uint32_t m_bUseUniversalShopMode;
   uint32_t m_bUseCustomHeroXPValue;
   uint32_t m_bUseBaseGoldBountyOnHeroes;
   uint32_t m_bSameHeroSelectionEnabled;
   int32_t m_nHeroMinimapIconSize;
   float m_flCreepMinimapIconScale;
   float m_flRuneMinimapIconScale;
   DT_DOTA_AbilityDraftAbilityState m_AbilityDraftAbilities[48];
   int32_t m_nAbilityDraftPlayerTracker;
   int32_t m_nAbilityDraftRoundNumber;
   int32_t m_nAbilityDraftAdvanceSteps;
   int32_t m_nAbilityDraftPhase;
   int32_t m_nAbilityDraftHeroesChosen[12];
   int32_t m_nARDMHeroesRemaining[6];
   int32_t m_nARDMHeroesPrecachedPercent;
   int32_t m_nAllDraftPhase;
   uint32_t m_bAllDraftRadiantFirst;
   uint32_t m_bHasHeroStatueLiked[100];
};

struct CDOTAGamerulesProxy : public CGameRulesProxy
{
   DT_DOTAGamerules dota_gamerules_data;
};

DeclareNetworkStruct(DT_DOTA_ItemStockInfo);
DeclareNetworkStruct(DT_DOTA_AssassinMinigameNetworkState);
DeclareNetworkStruct(DT_DOTA_AbilityDraftAbilityState);
DeclareNetworkStruct(DT_DOTAGamerules);
DeclareNetworkClass(CDOTAGamerulesProxy);

}
