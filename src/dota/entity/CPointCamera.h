#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CPointCamera : public CBaseEntity
{
   float m_FOV;
   float m_Resolution;
   uint32_t m_bFogEnable;
   uint32_t m_FogColor;
   float m_flFogStart;
   float m_flFogEnd;
   float m_flFogMaxDensity;
   uint32_t m_bActive;
   uint32_t m_bUseScreenAspectRatio;
   uint32_t m_bNoSky;
   float m_fBrightness;
};

DeclareClientClass(CPointCamera);

}
