#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CTEParticleSystem.h"

namespace dota
{

struct CTELargeFunnel : public CTEParticleSystem
{
   int32_t m_nModelIndex;
   uint32_t m_nReversed;
};

DeclareNetworkClass(CTELargeFunnel);

}
