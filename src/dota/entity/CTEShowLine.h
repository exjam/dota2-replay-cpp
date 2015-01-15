#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector3f.h"
#include "CTEParticleSystem.h"

namespace dota
{

struct CTEShowLine : public CTEParticleSystem
{
   Vector3f m_vecEnd;
};

DeclareNetworkClass(CTEShowLine);

}
