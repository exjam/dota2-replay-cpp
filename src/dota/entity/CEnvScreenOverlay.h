#pragma once
#include <cstdint>
#include "networkclass.h"
#include <string>
#include <vector>
#include "CBaseEntity.h"

namespace dota
{

struct CEnvScreenOverlay : public CBaseEntity
{
   std::vector<std::string> m_iszOverlayNames;
   std::vector<float> m_flOverlayTimes;
   float m_flStartTime;
   int32_t m_iDesiredOverlay;
   uint32_t m_bIsActive;
};

DeclareNetworkClass(CEnvScreenOverlay);

}
