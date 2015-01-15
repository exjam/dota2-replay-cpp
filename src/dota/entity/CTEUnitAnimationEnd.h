#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseTempEntity.h"

namespace dota
{

struct CTEUnitAnimationEnd : public CBaseTempEntity
{
   uint32_t m_hEntity;
   uint32_t m_bSnap;
};

DeclareNetworkClass(CTEUnitAnimationEnd);

}
