#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CDOTA_NeutralSpawner : public CBaseEntity
{
   uint32_t m_Type;
};

DeclareClientClass(CDOTA_NeutralSpawner);

}
