#pragma once
#include <cstdint>
#include "networkclass.h"

namespace dota
{

struct CDOTA_DataSpectator
{
   uint32_t m_hPrimaryRune;
   uint32_t m_hSecondaryRune;
   uint32_t m_iNetWorth[10];
};

DeclareNetworkClass(CDOTA_DataSpectator);

}
