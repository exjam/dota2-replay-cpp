#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CDOTA_Hero_Recorder : public CBaseEntity
{
   uint32_t m_bStartRecording;
   uint32_t m_hHero;
   uint32_t m_hPlayer;
};

DeclareClientClass(CDOTA_Hero_Recorder);

}
