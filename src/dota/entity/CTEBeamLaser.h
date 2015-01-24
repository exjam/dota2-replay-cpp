#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CTEBaseBeam.h"

namespace dota
{

struct CTEBeamLaser : public CTEBaseBeam
{
   uint32_t m_nStartEntity;
   uint32_t m_nEndEntity;
};

DeclareClientClass(CTEBeamLaser);

}
