#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector3f.h"

namespace dota
{

struct CTEMetalSparks
{
   Vector3f m_vecPos;
   Vector3f m_vecDir;
};

DeclareClientClass(CTEMetalSparks);

}
