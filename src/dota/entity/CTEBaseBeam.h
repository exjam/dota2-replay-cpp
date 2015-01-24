#pragma once
#include <cstdint>
#include "clientclass.h"

namespace dota
{

struct CTEBaseBeam
{
   int32_t m_nModelIndex;
   int32_t m_nHaloIndex;
   uint32_t m_nStartFrame;
   uint32_t m_nFrameRate;
   float m_fLife;
   float m_fWidth;
   float m_fEndWidth;
   uint32_t m_nFadeLength;
   float m_fAmplitude;
   uint32_t m_nSpeed;
   uint32_t r;
   uint32_t g;
   uint32_t b;
   uint32_t a;
   uint32_t m_nFlags;
};

DeclareClientClass(CTEBaseBeam);

}
