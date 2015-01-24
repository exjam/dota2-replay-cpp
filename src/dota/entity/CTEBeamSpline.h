#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector3f.h"
#include <vector>

namespace dota
{

struct CTEBeamSpline
{
   uint32_t m_nPoints;
   std::vector<Vector3f> m_vecPoints;
};

DeclareClientClass(CTEBeamSpline);

}
