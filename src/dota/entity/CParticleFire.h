#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector3f.h"

namespace dota
{

struct CParticleFire
{
   Vector3f m_vOrigin;
   Vector3f m_vDirection;
};

DeclareClientClass(CParticleFire);

}
