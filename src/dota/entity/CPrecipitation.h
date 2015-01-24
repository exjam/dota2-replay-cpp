#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CPrecipitation : public CBaseEntity
{
   uint32_t m_nPrecipType;
};

DeclareClientClass(CPrecipitation);

}
