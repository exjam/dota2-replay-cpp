#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CDOTA_Item.h"

namespace dota
{

struct CDOTA_Item_EmptyBottle : public CDOTA_Item
{
   int32_t m_iStoredRuneType;
};

DeclareClientClass(CDOTA_Item_EmptyBottle);

}
