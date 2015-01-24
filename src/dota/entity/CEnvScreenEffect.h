#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CEnvScreenEffect : public CBaseEntity
{
   float m_flDuration;
   uint32_t m_nType;
};

DeclareClientClass(CEnvScreenEffect);

}
