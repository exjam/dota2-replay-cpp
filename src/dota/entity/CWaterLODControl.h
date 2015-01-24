#pragma once
#include <cstdint>
#include "clientclass.h"

namespace dota
{

struct CWaterLODControl
{
   float m_flCheapWaterStartDistance;
   float m_flCheapWaterEndDistance;
};

DeclareClientClass(CWaterLODControl);

}
