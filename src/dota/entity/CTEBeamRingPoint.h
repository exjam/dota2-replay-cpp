#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector3f.h"
#include "CTEBaseBeam.h"

namespace dota
{

struct CTEBeamRingPoint : public CTEBaseBeam
{
   Vector3f m_vecCenter;
   float m_flStartRadius;
   float m_flEndRadius;
};

DeclareClientClass(CTEBeamRingPoint);

}
