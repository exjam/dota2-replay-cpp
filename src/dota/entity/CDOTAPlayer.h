#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector2f.h"
#include "vector3f.h"
#include <string>
#include "CBasePlayer.h"

namespace dota
{

struct DT_DOTACompendiumData
{
   int32_t m_iTotalEarnedGold;
   int32_t m_iTotalEarnedXP;
};

struct DT_ClientQuickBuyItemState
{
   int32_t nItemType;
   uint32_t bPurchasable;
};

struct DT_DOTACommentatorTable
{
   uint32_t m_cellbits;
   Vector2f m_vecOrigin;
   uint32_t m_cellX;
   uint32_t m_cellY;
   uint32_t m_cellZ;
   int32_t m_iSpectatorClickBehavior;
   uint32_t m_iCursor[2];
   float m_flAspectRatio;
   uint32_t m_hSpectatorQueryUnit;
   uint32_t m_iStatsPanel;
   uint32_t m_iShopPanel;
   uint32_t m_iShopViewMode;
   uint32_t m_iStatsDropdownCategory;
   uint32_t m_iStatsDropdownSort;
   std::string m_szShopString;
   DT_ClientQuickBuyItemState m_vecClientQuickBuyState[16];
   uint32_t m_iQuickBuyParity;
   uint32_t m_bInShowCaseMode;
   float m_flCameraZoomAmount;
   int32_t m_iHighPriorityScore;
};

struct CDOTAPlayer : public CBasePlayer
{
   int32_t m_nTickBase;
   int32_t m_iPlayerID;
   int32_t m_nCachedCoachedTeam;
   Vector3f m_vecStartingPosition;
   uint32_t m_hAssignedHero;
   int32_t m_iMusicStatus;
   float m_flMusicOperatorVals[3];
   uint32_t m_iMusicOperatorVals[4];
   uint32_t m_hKillCamUnit;
   DT_DOTACommentatorTable dota_commentator_table;
   DT_DOTACompendiumData dota_compendium_data;
   uint32_t m_bUsingCameraMan;
   uint32_t m_bUsingAssistedCameraOperator;
};

DeclareNetworkStruct(DT_DOTACompendiumData);
DeclareNetworkStruct(DT_ClientQuickBuyItemState);
DeclareNetworkStruct(DT_DOTACommentatorTable);
DeclareNetworkClass(CDOTAPlayer);

}
