#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseAnimating.h"

namespace dota
{

struct CDOTA_Item_Physical : public CBaseAnimating
{
   uint32_t m_hItem;
};

DeclareNetworkClass(CDOTA_Item_Physical);

}
