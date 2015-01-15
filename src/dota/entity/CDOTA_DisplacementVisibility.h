#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CDOTA_DisplacementVisibility : public CBaseEntity
{
   int32_t m_HiddenDisplacement;
};

DeclareNetworkClass(CDOTA_DisplacementVisibility);

}
