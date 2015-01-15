#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CPrecipitation : public CBaseEntity
{
   uint32_t m_nPrecipType;
};

DeclareNetworkClass(CPrecipitation);

}
