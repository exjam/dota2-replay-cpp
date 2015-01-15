#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CEnvScreenEffect : public CBaseEntity
{
   float m_flDuration;
   uint32_t m_nType;
};

DeclareNetworkClass(CEnvScreenEffect);

}
