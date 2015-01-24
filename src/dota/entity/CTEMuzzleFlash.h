#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector3f.h"
#include "CBaseTempEntity.h"

namespace dota
{

struct CTEMuzzleFlash : public CBaseTempEntity
{
   Vector3f m_vecOrigin;
   Vector3f m_vecAngles;
   float m_flScale;
   uint32_t m_nType;
};

DeclareClientClass(CTEMuzzleFlash);

}
