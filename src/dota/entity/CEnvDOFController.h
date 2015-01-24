#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CEnvDOFController : public CBaseEntity
{
   uint32_t m_bDOFEnabled;
   float m_flNearBlurDepth;
   float m_flNearFocusDepth;
   float m_flFarFocusDepth;
   float m_flFarBlurDepth;
   float m_flNearBlurRadius;
   float m_flFarBlurRadius;
};

DeclareClientClass(CEnvDOFController);

}
