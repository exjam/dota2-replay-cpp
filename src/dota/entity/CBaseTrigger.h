#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseToggle.h"

namespace dota
{

struct CBaseTrigger : public CBaseToggle
{
   uint32_t m_bClientSidePredicted;
   int32_t m_spawnflags;
};

DeclareNetworkClass(CBaseTrigger);

}
