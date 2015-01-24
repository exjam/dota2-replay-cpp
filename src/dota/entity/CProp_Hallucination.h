#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseAnimating.h"

namespace dota
{

struct CProp_Hallucination : public CBaseAnimating
{
   uint32_t m_bEnabled;
   float m_fVisibleTime;
   float m_fRechargeTime;
};

DeclareClientClass(CProp_Hallucination);

}
