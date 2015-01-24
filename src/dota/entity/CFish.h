#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector3f.h"

namespace dota
{

struct CFish
{
   Vector3f m_poolOrigin;
   float m_angle;
   float m_x;
   float m_y;
   float m_z;
   int32_t m_nModelIndex;
   int32_t m_lifeState;
   float m_waterLevel;
};

DeclareClientClass(CFish);

}
