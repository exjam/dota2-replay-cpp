#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector3f.h"

namespace dota
{

struct CTEEnergySplash
{
   Vector3f m_vecPos;
   Vector3f m_vecDir;
   uint32_t m_bExplosive;
};

DeclareNetworkClass(CTEEnergySplash);

}
