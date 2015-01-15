#pragma once
#include <cstdint>
#include "networkclass.h"
#include <string>

namespace dota
{

struct CDotaQuest
{
   std::string m_pszQuestTitle;
   std::string m_pszQuestText;
   uint32_t m_nQuestType;
   uint32_t m_hSubquests[8];
   uint32_t m_bHidden;
   uint32_t m_bCompleted;
   uint32_t m_bWinIfCompleted;
   uint32_t m_bLoseIfCompleted;
   std::string m_pszGameEndText;
   int32_t m_pnTextReplaceValuesCDotaQuest[4];
   std::string m_pszTextReplaceString;
   int32_t m_nTextReplaceValueVersion;
};

DeclareNetworkClass(CDotaQuest);

}
