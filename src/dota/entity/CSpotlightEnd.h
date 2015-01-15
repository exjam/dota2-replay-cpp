#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CSpotlightEnd : public CBaseEntity
{
   float m_flLightScale;
   float m_Radius;
};

DeclareNetworkClass(CSpotlightEnd);

}
