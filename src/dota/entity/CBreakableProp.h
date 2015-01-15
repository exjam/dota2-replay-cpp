#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseAnimating.h"

namespace dota
{

struct CBreakableProp : public CBaseAnimating
{
   uint32_t m_bClientPhysics;
};

DeclareNetworkClass(CBreakableProp);

}
