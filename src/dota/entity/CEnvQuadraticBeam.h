#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector3f.h"
#include "CBaseEntity.h"

namespace dota
{

struct CEnvQuadraticBeam : public CBaseEntity
{
   Vector3f m_targetPosition;
   Vector3f m_controlPosition;
   float m_scrollRate;
   float m_flWidth;
};

DeclareClientClass(CEnvQuadraticBeam);

}
