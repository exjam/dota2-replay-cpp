#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector3f.h"

namespace dota
{

struct CBeam
{
   uint32_t m_nBeamType;
   uint32_t m_nBeamFlags;
   uint32_t m_nNumBeamEnts;
   uint32_t m_hAttachEntity[10];
   uint32_t m_nAttachIndex[10];
   uint32_t m_nHaloIndex;
   float m_fHaloScale;
   float m_fWidth;
   float m_fEndWidth;
   float m_fFadeLength;
   float m_fAmplitude;
   float m_fStartFrame;
   float m_fSpeed;
   uint32_t m_nRenderFX;
   uint32_t m_nRenderMode;
   float m_flFrameRate;
   float m_flHDRColorScale;
   float m_flFrame;
   uint32_t m_clrRender;
   uint32_t m_nClipStyle;
   Vector3f m_vecEndPos;
   int32_t m_nModelIndex;
   Vector3f m_vecOrigin;
   uint32_t moveparent;
};

DeclareClientClass(CBeam);

}
