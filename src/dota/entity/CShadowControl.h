#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector3f.h"

namespace dota
{

struct CShadowControl
{
   Vector3f m_shadowDirection;
   uint32_t m_shadowColor;
   float m_flShadowMaxDist;
   uint32_t m_bDisableShadows;
   uint32_t m_bEnableLocalLightShadows;
};

DeclareClientClass(CShadowControl);

}
