#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CParticlePerformanceMonitor : public CBaseEntity
{
   uint32_t m_bDisplayPerf;
   uint32_t m_bMeasurePerf;
};

DeclareClientClass(CParticlePerformanceMonitor);

}
