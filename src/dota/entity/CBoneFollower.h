#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CBoneFollower : public CBaseEntity
{
   int32_t m_modelIndex;
   uint32_t m_solidIndex;
};

DeclareNetworkClass(CBoneFollower);

}
