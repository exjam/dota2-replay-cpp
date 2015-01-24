#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CDynamicLight : public CBaseEntity
{
   uint32_t m_Flags;
   uint32_t m_LightStyle;
   float m_Radius;
   int32_t m_Exponent;
   float m_InnerAngle;
   float m_OuterAngle;
   float m_SpotRadius;
};

DeclareClientClass(CDynamicLight);

}
