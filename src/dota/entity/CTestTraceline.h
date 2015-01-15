#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector2f.h"
#include "vector3f.h"

namespace dota
{

struct CTestTraceline
{
   uint32_t m_clrRender;
   Vector3f m_vecOrigin;
   Vector3f m_angRotation;
   uint32_t moveparent;
};

DeclareNetworkClass(CTestTraceline);

}
