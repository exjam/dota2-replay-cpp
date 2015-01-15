#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector3f.h"
#include <vector>

namespace dota
{

struct CTEBeamSpline
{
   uint32_t m_nPoints;
   std::vector<Vector3f> m_vecPoints;
};

DeclareNetworkClass(CTEBeamSpline);

}
