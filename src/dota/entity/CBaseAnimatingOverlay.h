#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseAnimating.h"

namespace dota
{

struct DT_Animationlayer
{
   uint32_t m_nSequence;
   float m_flCycle;
   float m_flPrevCycle;
   float m_flWeight;
   uint32_t m_nOrder;
};

struct DT_OverlayVars
{
   DT_Animationlayer m_AnimOverlay[15];
};

struct CBaseAnimatingOverlay : public CBaseAnimating
{
   DT_OverlayVars overlay_vars;
};

DeclareNetworkStruct(DT_Animationlayer);
DeclareNetworkStruct(DT_OverlayVars);
DeclareNetworkClass(CBaseAnimatingOverlay);

}
