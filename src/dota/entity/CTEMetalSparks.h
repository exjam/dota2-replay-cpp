#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector3f.h"

namespace dota
{

struct CTEMetalSparks
{
   Vector3f m_vecPos;
   Vector3f m_vecDir;
};

DeclareNetworkClass(CTEMetalSparks);

}
