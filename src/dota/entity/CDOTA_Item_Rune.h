#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseAnimating.h"

namespace dota
{

struct CDOTA_Item_Rune : public CBaseAnimating
{
   uint32_t m_iRuneType;
};

DeclareClientClass(CDOTA_Item_Rune);

}
