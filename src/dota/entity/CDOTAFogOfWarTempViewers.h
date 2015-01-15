#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CDOTAFogOfWarTempViewers : public CBaseEntity
{
   uint32_t m_bTempViewers[300];
};

DeclareNetworkClass(CDOTAFogOfWarTempViewers);

}
