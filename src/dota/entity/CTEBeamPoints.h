#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector3f.h"
#include "CTEBaseBeam.h"

namespace dota
{

struct CTEBeamPoints : public CTEBaseBeam
{
   Vector3f m_vecStartPoint;
   Vector3f m_vecEndPoint;
};

DeclareNetworkClass(CTEBeamPoints);

}
