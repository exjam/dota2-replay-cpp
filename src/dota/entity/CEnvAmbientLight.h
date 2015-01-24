#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector3f.h"
#include "CSpatialEntity.h"

namespace dota
{

struct CEnvAmbientLight : public CSpatialEntity
{
   Vector3f m_vecColor;
};

DeclareClientClass(CEnvAmbientLight);

}
