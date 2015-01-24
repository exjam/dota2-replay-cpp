#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CTEParticleSystem.h"

namespace dota
{

struct CTELargeFunnel : public CTEParticleSystem
{
   int32_t m_nModelIndex;
   uint32_t m_nReversed;
};

DeclareClientClass(CTELargeFunnel);

}
