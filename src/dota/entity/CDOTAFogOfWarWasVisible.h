#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CDOTAFogOfWarWasVisible : public CBaseEntity
{
   uint64_t m_bWasVisible[1024];
};

DeclareClientClass(CDOTAFogOfWarWasVisible);

}
