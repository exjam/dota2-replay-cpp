#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseToggle.h"

namespace dota
{

struct CBaseDoor : public CBaseToggle
{
   float m_flWaveHeight;
};

DeclareNetworkClass(CBaseDoor);

}
