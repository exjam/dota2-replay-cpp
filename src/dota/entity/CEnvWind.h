#pragma once
#include <cstdint>
#include "networkclass.h"

namespace dota
{

struct DT_EnvWindShared
{
   uint32_t m_iMinWind;
   uint32_t m_iMaxWind;
   uint32_t m_iMinGust;
   uint32_t m_iMaxGust;
   int32_t m_windRadius;
   float m_flMinGustDelay;
   float m_flMaxGustDelay;
   uint32_t m_iGustDirChange;
   uint32_t m_iWindSeed;
   uint32_t m_iInitialWindDir;
   float m_flInitialWindSpeed;
   float m_flStartTime;
   float m_flGustDuration;
};

struct CEnvWind
{
   DT_EnvWindShared m_EnvWindShared;
};

DeclareNetworkStruct(DT_EnvWindShared);
DeclareNetworkClass(CEnvWind);

}
