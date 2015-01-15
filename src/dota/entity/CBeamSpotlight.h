#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CBeamSpotlight : public CBaseEntity
{
   uint32_t m_nHaloIndex;
   uint32_t m_bSpotlightOn;
   uint32_t m_bHasDynamicLight;
   float m_flSpotlightMaxLength;
   float m_flSpotlightGoalWidth;
   float m_flHDRColorScale;
   float m_flRotationSpeed;
   uint32_t m_nRotationAxis;
};

DeclareNetworkClass(CBeamSpotlight);

}
