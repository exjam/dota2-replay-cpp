#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector3f.h"
#include "CBaseAnimatingOverlay.h"

namespace dota
{

struct CBaseFlex : public CBaseAnimatingOverlay
{
   float m_flexWeight[96];
   uint32_t m_blinktoggle;
   Vector3f m_viewtarget;
};

DeclareNetworkClass(CBaseFlex);

}
