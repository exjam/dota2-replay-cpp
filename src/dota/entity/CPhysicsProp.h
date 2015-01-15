#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBreakableProp.h"

namespace dota
{

struct CPhysicsProp : public CBreakableProp
{
   uint32_t m_bAwake;
};

DeclareNetworkClass(CPhysicsProp);

}
