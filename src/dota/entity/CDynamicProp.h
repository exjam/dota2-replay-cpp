#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBreakableProp.h"

namespace dota
{

struct CDynamicProp : public CBreakableProp
{
   uint32_t m_bUseHitboxesForRenderBox;
};

DeclareNetworkClass(CDynamicProp);

}
