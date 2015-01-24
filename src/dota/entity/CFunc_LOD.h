#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CFunc_LOD : public CBaseEntity
{
   uint32_t m_nDisappearMinDist;
   uint32_t m_nDisappearMaxDist;
};

DeclareClientClass(CFunc_LOD);

}
