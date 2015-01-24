#pragma once
#include <cstdint>
#include "clientclass.h"
#include <string>
#include <vector>

namespace dota
{

struct CTeam
{
   int32_t m_iTeamNum;
   int32_t m_iScore;
   int32_t m_iRoundsWon;
   std::string m_szTeamname;
   std::vector<uint32_t> player_array;
};

DeclareClientClass(CTeam);

}
