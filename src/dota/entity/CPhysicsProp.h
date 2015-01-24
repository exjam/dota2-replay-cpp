#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBreakableProp.h"

namespace dota
{

struct CPhysicsProp : public CBreakableProp
{
   uint32_t m_bAwake;
};

DeclareClientClass(CPhysicsProp);

}
