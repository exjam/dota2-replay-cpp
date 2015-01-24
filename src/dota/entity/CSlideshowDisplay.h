#pragma once
#include <cstdint>
#include "clientclass.h"
#include <string>
#include "CBaseEntity.h"

namespace dota
{

struct CSlideshowDisplay : public CBaseEntity
{
   uint32_t m_bEnabled;
   std::string m_szDisplayText;
   std::string m_szSlideshowDirectory;
   uint32_t m_chCurrentSlideLists[16];
   float m_fMinSlideTime;
   float m_fMaxSlideTime;
   uint32_t m_iCycleType;
   uint32_t m_bNoListRepeats;
};

DeclareClientClass(CSlideshowDisplay);

}
