#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTA_Item.h"

namespace dota
{

struct CDOTA_Item_PowerTreads : public CDOTA_Item
{
   uint32_t m_iStat;
};

DeclareNetworkClass(CDOTA_Item_PowerTreads);

}
