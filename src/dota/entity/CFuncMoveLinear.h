#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector3f.h"
#include "CBaseToggle.h"

namespace dota
{

struct CFuncMoveLinear : public CBaseToggle
{
   Vector3f m_vecVelocity;
   uint32_t m_fFlags;
};

DeclareNetworkClass(CFuncMoveLinear);

}
