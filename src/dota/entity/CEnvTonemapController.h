#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CEnvTonemapController : public CBaseEntity
{
   uint32_t m_bUseCustomAutoExposureMin;
   uint32_t m_bUseCustomAutoExposureMax;
   uint32_t m_bUseCustomBloomScale;
   float m_flCustomAutoExposureMin;
   float m_flCustomAutoExposureMax;
   float m_flCustomBloomScale;
   float m_flCustomBloomScaleMinimum;
   float m_flBloomExponent;
   float m_flBloomSaturation;
};

DeclareNetworkClass(CEnvTonemapController);

}
