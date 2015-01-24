#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseToggle.h"

namespace dota
{

struct CBaseTrigger : public CBaseToggle
{
   uint32_t m_bClientSidePredicted;
   int32_t m_spawnflags;
};

DeclareClientClass(CBaseTrigger);

}
