#pragma once
#include <cstdint>
#include "clientclass.h"
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

DeclareClientClass(CTeamShowcasePlayer);

}
