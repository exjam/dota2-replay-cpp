#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseAnimating.h"

namespace dota
{

struct CProp_Hallucination : public CBaseAnimating
{
   uint32_t m_bEnabled;
   float m_fVisibleTime;
   float m_fRechargeTime;
};

DeclareNetworkClass(CProp_Hallucination);

}
