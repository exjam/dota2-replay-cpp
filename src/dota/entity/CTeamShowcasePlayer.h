#pragma once
#include <cstdint>
#include "networkclass.h"
#include <string>
#include "CBaseEntity.h"

namespace dota
{

struct CTeamShowcasePlayer : public CBaseEntity
{
   uint32_t m_hPlayerEntity;
   std::string m_szCameraAnim;
   float m_flTransitionTime;
};

DeclareNetworkClass(CTeamShowcasePlayer);

}
