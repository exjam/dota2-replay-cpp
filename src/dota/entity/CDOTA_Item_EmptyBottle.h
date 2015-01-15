#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTA_Item.h"

namespace dota
{

struct CDOTA_Item_EmptyBottle : public CDOTA_Item
{
   int32_t m_iStoredRuneType;
};

DeclareNetworkClass(CDOTA_Item_EmptyBottle);

}
