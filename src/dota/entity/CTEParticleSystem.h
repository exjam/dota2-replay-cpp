#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector2f.h"
#include "vector3f.h"
#include "CBaseTempEntity.h"

namespace dota
{

struct CTEParticleSystem : public CBaseTempEntity
{
   Vector3f m_vecOrigin;
};

DeclareNetworkClass(CTEParticleSystem);

}
