#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseTempEntity.h"

namespace dota
{

struct CTEUnitAnimation : public CBaseTempEntity
{
   float m_flCastPoint;
   uint32_t m_hEntity;
   float m_flPlaybackRate;
   uint32_t m_iSequenceIndex;
   uint32_t m_iType;
   int32_t m_Activity;
};

DeclareNetworkClass(CTEUnitAnimation);

}
