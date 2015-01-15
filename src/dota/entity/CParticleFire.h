#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector3f.h"

namespace dota
{

struct CParticleFire
{
   Vector3f m_vOrigin;
   Vector3f m_vDirection;
};

DeclareNetworkClass(CParticleFire);

}
