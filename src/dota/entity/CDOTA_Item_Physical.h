#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseAnimating.h"

namespace dota
{

struct CDOTA_Item_Physical : public CBaseAnimating
{
   uint32_t m_hItem;
};

DeclareClientClass(CDOTA_Item_Physical);

}
