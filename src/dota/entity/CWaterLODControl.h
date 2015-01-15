#pragma once
#include <cstdint>
#include "networkclass.h"

namespace dota
{

struct CWaterLODControl
{
   float m_flCheapWaterStartDistance;
   float m_flCheapWaterEndDistance;
};

DeclareNetworkClass(CWaterLODControl);

}
