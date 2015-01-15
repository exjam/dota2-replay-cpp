#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseTempEntity.h"

namespace dota
{

struct CTEDotaBloodImpact : public CBaseTempEntity
{
   uint32_t m_hEntity;
   float m_flScale;
   float m_flXNormal;
   float m_flYNormal;
};

DeclareNetworkClass(CTEDotaBloodImpact);

}
