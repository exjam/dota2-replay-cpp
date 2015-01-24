#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CDOTA_Item.h"

namespace dota
{

struct CDOTA_Item_PowerTreads : public CDOTA_Item
{
   uint32_t m_iStat;
};

DeclareClientClass(CDOTA_Item_PowerTreads);

}
