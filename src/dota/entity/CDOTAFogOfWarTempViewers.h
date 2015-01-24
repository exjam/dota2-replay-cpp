#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CDOTAFogOfWarTempViewers : public CBaseEntity
{
   uint32_t m_bTempViewers[300];
};

DeclareClientClass(CDOTAFogOfWarTempViewers);

}
