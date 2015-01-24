#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector3f.h"
#include "CBaseTempEntity.h"

namespace dota
{

struct CTEPlayerDecal : public CBaseTempEntity
{
   Vector3f m_vecOrigin;
   uint32_t m_nEntity;
   uint32_t m_nPlayer;
};

DeclareClientClass(CTEPlayerDecal);

}
