#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector3f.h"
#include "CTEParticleSystem.h"

namespace dota
{

struct CTEBloodStream : public CTEParticleSystem
{
   Vector3f m_vecDirection;
   uint32_t r;
   uint32_t g;
   uint32_t b;
   uint32_t a;
   uint32_t m_nAmount;
};

DeclareClientClass(CTEBloodStream);

}
