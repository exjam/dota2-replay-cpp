#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector3f.h"
#include <string>

namespace dota
{

struct CColorCorrection
{
   Vector3f m_vecOrigin;
   float m_MinFalloff;
   float m_MaxFalloff;
   float m_flCurWeight;
   float m_flMaxWeight;
   float m_flFadeInDuration;
   float m_flFadeOutDuration;
   std::string m_netlookupFilename;
   uint32_t m_bEnabled;
   uint32_t m_bMaster;
   uint32_t m_bClientSide;
   uint32_t m_bExclusive;
};

DeclareClientClass(CColorCorrection);

}
