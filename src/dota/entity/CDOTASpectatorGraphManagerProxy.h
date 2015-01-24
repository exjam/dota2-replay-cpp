#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct DT_DOTASpectatorGraphManager
{
   uint32_t m_rgPlayerGraphData[10];
   uint32_t m_rgRadiantTotalEarnedGold[64];
   uint32_t m_rgDireTotalEarnedGold[64];
   uint32_t m_rgRadiantTotalEarnedXP[64];
   uint32_t m_rgDireTotalEarnedXP[64];
   uint32_t m_rgRadiantNetWorth[64];
   uint32_t m_rgDireNetWorth[64];
   float m_flTotalEarnedGoldStartTime;
   float m_flTotalEarnedGoldEndTime;
   uint32_t m_nGoldGraphVersion;
};

struct CDOTASpectatorGraphManagerProxy : public CBaseEntity
{
   DT_DOTASpectatorGraphManager dota_spectator_graph_manager_data;
};

DeclareClientStruct(DT_DOTASpectatorGraphManager);
DeclareClientClass(CDOTASpectatorGraphManagerProxy);

}
