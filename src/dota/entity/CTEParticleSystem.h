#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector2f.h"
#include "vector3f.h"
#include "CBaseTempEntity.h"

namespace dota
{

struct CTEParticleSystem : public CBaseTempEntity
{
   Vector3f m_vecOrigin;
};

DeclareClientClass(CTEParticleSystem);

}
