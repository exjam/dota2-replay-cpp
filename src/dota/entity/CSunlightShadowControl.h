#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector3f.h"
#include <string>

namespace dota
{

struct CSunlightShadowControl
{
   Vector3f m_shadowDirection;
   uint32_t m_bEnabled;
   std::string m_TextureName;
   uint32_t m_LightColor;
   float m_flColorTransitionTime;
   float m_flSunDistance;
   float m_flFOV;
   float m_flNearZ;
   float m_flNorthOffset;
   uint32_t m_bEnableShadows;
};

DeclareClientClass(CSunlightShadowControl);

}
