#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CDOTA_NeutralSpawner : public CBaseEntity
{
   uint32_t m_Type;
};

DeclareNetworkClass(CDOTA_NeutralSpawner);

}
