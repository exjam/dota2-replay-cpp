#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector3f.h"

namespace dota
{

struct CTEBloodSprite
{
   Vector3f m_vecOrigin;
   Vector3f m_vecDirection;
   uint32_t r;
   uint32_t g;
   uint32_t b;
   uint32_t a;
   int32_t m_nSprayModel;
   int32_t m_nDropModel;
   uint32_t m_nSize;
};

DeclareClientClass(CTEBloodSprite);

}
