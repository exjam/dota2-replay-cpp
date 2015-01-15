#pragma once
#include <cstdint>
#include "networkclass.h"
#include <string>
#include "CTeam.h"

namespace dota
{

struct CDOTATeam : public CTeam
{
   uint32_t m_iHeroKills;
   uint32_t m_iTowerKills;
   uint32_t m_iBarracksKills;
   uint32_t m_unTournamentTeamID;
   uint64_t m_ulTeamLogo;
   uint64_t m_ulTeamBaseLogo;
   uint64_t m_ulTeamBannerLogo;
   std::string m_szTag;
   uint32_t m_bTeamComplete;
};

DeclareNetworkClass(CDOTATeam);

}
