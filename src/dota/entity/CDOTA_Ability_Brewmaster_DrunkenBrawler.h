#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CDOTABaseAbility.h"

namespace dota
{

struct CDOTA_Ability_Brewmaster_DrunkenBrawler : public CDOTABaseAbility
{
   int32_t m_iBrawlActive;
};

DeclareClientClass(CDOTA_Ability_Brewmaster_DrunkenBrawler);

}
