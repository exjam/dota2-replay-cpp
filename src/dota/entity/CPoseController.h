#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CPoseController : public CBaseEntity
{
   uint32_t m_hProps[4];
   uint32_t m_chPoseIndex[4];
   uint32_t m_bPoseValueParity;
   float m_fPoseValue;
   float m_fInterpolationTime;
   uint32_t m_bInterpolationWrap;
   float m_fCycleFrequency;
   uint32_t m_nFModType;
   float m_fFModTimeOffset;
   float m_fFModRate;
   float m_fFModAmplitude;
};

DeclareClientClass(CPoseController);

}
