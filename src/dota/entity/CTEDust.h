#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector3f.h"
#include "CTEParticleSystem.h"

namespace dota
{

struct CTEDust : public CTEParticleSystem
{
   float m_flSize;
   float m_flSpeed;
   Vector3f m_vecDirection;
};

DeclareClientClass(CTEDust);

}
