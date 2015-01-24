#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CPlasma : public CBaseEntity
{
   float m_flScale;
   float m_flScaleTime;
   uint32_t m_nFlags;
   int32_t m_nPlasmaModelIndex;
   int32_t m_nPlasmaModelIndex2;
   int32_t m_nGlowModelIndex;
};

DeclareClientClass(CPlasma);

}
