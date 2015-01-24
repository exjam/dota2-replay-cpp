#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseAnimating.h"

namespace dota
{

struct CBreakableProp : public CBaseAnimating
{
   uint32_t m_bClientPhysics;
};

DeclareClientClass(CBreakableProp);

}
