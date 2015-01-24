#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CBoneFollower : public CBaseEntity
{
   int32_t m_modelIndex;
   uint32_t m_solidIndex;
};

DeclareClientClass(CBoneFollower);

}
