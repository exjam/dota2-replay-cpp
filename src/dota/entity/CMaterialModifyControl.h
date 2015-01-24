#pragma once
#include <cstdint>
#include "clientclass.h"
#include <string>
#include "CBaseEntity.h"

namespace dota
{

struct CMaterialModifyControl : public CBaseEntity
{
   std::string m_szMaterialName;
   std::string m_szMaterialVar;
   std::string m_szMaterialVarValue;
   int32_t m_iFrameStart;
   int32_t m_iFrameEnd;
   uint32_t m_bWrap;
   float m_flFramerate;
   uint32_t m_bNewAnimCommandsSemaphore;
   float m_flFloatLerpStartValue;
   float m_flFloatLerpEndValue;
   float m_flFloatLerpTransitionTime;
   uint32_t m_nModifyMode;
};

DeclareClientClass(CMaterialModifyControl);

}
