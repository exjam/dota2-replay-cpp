#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CTEBaseBeam.h"

namespace dota
{

struct CTEBeamFollow : public CTEBaseBeam
{
   uint32_t m_iEntIndex;
};

DeclareNetworkClass(CTEBeamFollow);

}
