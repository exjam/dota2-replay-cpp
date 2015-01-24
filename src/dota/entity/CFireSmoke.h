#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CFireSmoke : public CBaseEntity
{
   float m_flStartScale;
   float m_flScale;
   float m_flScaleTime;
   uint32_t m_nFlags;
   int32_t m_nFlameModelIndex;
   int32_t m_nFlameFromAboveModelIndex;
};

DeclareClientClass(CFireSmoke);

}
