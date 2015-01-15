#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector3f.h"
#include <string>
#include "CBaseEntity.h"

namespace dota
{

struct CWorld : public CBaseEntity
{
   float m_flWaveHeight;
   Vector3f m_WorldMins;
   Vector3f m_WorldMaxs;
   uint32_t m_bStartDark;
   float m_flMaxOccludeeArea;
   float m_flMinOccluderArea;
   float m_flMaxPropScreenSpaceWidth;
   float m_flMinPropScreenSpaceWidth;
   std::string m_iszDetailSpriteMaterial;
   uint32_t m_bColdWorld;
};

DeclareNetworkClass(CWorld);

}
