#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CDOTASpecGraphPlayerData : public CBaseEntity
{
   uint32_t m_rgGoldPerMinute[64];
   uint32_t m_rgXPPerMinute[64];
   int32_t m_nCreatedByPlayerID;
};

DeclareClientClass(CDOTASpecGraphPlayerData);

}
