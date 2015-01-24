#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBreakableProp.h"

namespace dota
{

struct CDynamicProp : public CBreakableProp
{
   uint32_t m_bUseHitboxesForRenderBox;
};

DeclareClientClass(CDynamicProp);

}
