#pragma once
#include <cstdint>
#include "clientclass.h"
#include <string>

namespace dota
{

struct CDotaSubquestBase
{
   std::string m_pszSubquestText;
   uint32_t m_bHidden;
   uint32_t m_bCompleted;
   uint32_t m_bShowProgressBar;
   int32_t m_nProgressBarHueShift;
   int32_t m_pnTextReplaceValuesCDotaSubquestBase[2];
   std::string m_pszTextReplaceString;
   int32_t m_nTextReplaceValueVersion;
};

DeclareClientClass(CDotaSubquestBase);

}
