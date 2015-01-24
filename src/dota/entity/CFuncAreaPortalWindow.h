#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CFuncAreaPortalWindow : public CBaseEntity
{
   float m_flFadeDist;
   float m_flFadeStartDist;
   float m_flTranslucencyLimit;
   int32_t m_iBackgroundModelIndex;
};

DeclareClientClass(CFuncAreaPortalWindow);

}
