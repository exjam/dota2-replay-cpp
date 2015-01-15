#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector3f.h"

namespace dota
{

struct CSpatialEntity
{
   Vector3f m_vecOrigin;
   float m_MinFalloff;
   float m_MaxFalloff;
   float m_flCurWeight;
   uint32_t m_bEnabled;
};

DeclareNetworkClass(CSpatialEntity);

}
