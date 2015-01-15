#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector3f.h"
#include "CTEBaseBeam.h"

namespace dota
{

struct CTEBeamEntPoint : public CTEBaseBeam
{
   uint32_t m_nStartEntity;
   uint32_t m_nEndEntity;
   Vector3f m_vecStartPoint;
   Vector3f m_vecEndPoint;
};

DeclareNetworkClass(CTEBeamEntPoint);

}
