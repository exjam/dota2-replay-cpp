#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseToggle.h"

namespace dota
{

struct CBaseDoor : public CBaseToggle
{
   float m_flWaveHeight;
};

DeclareClientClass(CBaseDoor);

}
