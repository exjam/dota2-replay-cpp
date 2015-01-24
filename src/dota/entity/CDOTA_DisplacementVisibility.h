#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CDOTA_DisplacementVisibility : public CBaseEntity
{
   int32_t m_HiddenDisplacement;
};

DeclareClientClass(CDOTA_DisplacementVisibility);

}
