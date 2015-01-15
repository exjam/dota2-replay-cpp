#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CFunc_LOD : public CBaseEntity
{
   uint32_t m_nDisappearMinDist;
   uint32_t m_nDisappearMaxDist;
};

DeclareNetworkClass(CFunc_LOD);

}
