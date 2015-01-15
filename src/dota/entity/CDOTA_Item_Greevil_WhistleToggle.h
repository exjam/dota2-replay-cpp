#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTA_Item.h"

namespace dota
{

struct CDOTA_Item_Greevil_WhistleToggle : public CDOTA_Item
{
   uint32_t m_hGreevil;
};

DeclareNetworkClass(CDOTA_Item_Greevil_WhistleToggle);

}
