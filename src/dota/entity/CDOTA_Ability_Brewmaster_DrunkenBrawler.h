#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTABaseAbility.h"

namespace dota
{

struct CDOTA_Ability_Brewmaster_DrunkenBrawler : public CDOTABaseAbility
{
   int32_t m_iBrawlActive;
};

DeclareNetworkClass(CDOTA_Ability_Brewmaster_DrunkenBrawler);

}
