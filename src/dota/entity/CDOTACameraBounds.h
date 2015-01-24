#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector3f.h"
#include "CBaseEntity.h"

namespace dota
{

struct CDOTACameraBounds : public CBaseEntity
{
   Vector3f m_vecBoundsMin;
   Vector3f m_vecBoundsMax;
};

DeclareClientClass(CDOTACameraBounds);

}
