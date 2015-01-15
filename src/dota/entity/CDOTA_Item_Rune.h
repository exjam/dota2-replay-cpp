#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseAnimating.h"

namespace dota
{

struct CDOTA_Item_Rune : public CBaseAnimating
{
   uint32_t m_iRuneType;
};

DeclareNetworkClass(CDOTA_Item_Rune);

}
