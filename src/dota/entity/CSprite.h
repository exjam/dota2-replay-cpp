#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CSprite : public CBaseEntity
{
   uint32_t m_hAttachedToEntity;
   int32_t m_nAttachment;
   float m_flScaleTime;
   float m_flSpriteScale;
   float m_flGlowProxySize;
   float m_flHDRColorScale;
   float m_flSpriteFramerate;
   float m_flFrame;
   float m_flBrightnessTime;
   uint32_t m_nBrightness;
   uint32_t m_bWorldSpaceScale;
};

DeclareClientClass(CSprite);

}
