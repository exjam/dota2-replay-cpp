#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CTEBaseBeam.h"

namespace dota
{

struct CTEBeamFollow : public CTEBaseBeam
{
   uint32_t m_iEntIndex;
};

DeclareClientClass(CTEBeamFollow);

}
