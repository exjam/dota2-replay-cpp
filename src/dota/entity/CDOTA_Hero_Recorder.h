#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CDOTA_Hero_Recorder : public CBaseEntity
{
   uint32_t m_bStartRecording;
   uint32_t m_hHero;
   uint32_t m_hPlayer;
};

DeclareNetworkClass(CDOTA_Hero_Recorder);

}
