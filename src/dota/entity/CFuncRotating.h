#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector2f.h"
#include "vector3f.h"
#include "CBaseEntity.h"

namespace dota
{

struct CFuncRotating : public CBaseEntity
{
   Vector3f m_vecOrigin;
   Vector3f m_angRotation;
   uint32_t m_flSimulationTime;
};

DeclareClientClass(CFuncRotating);

}
