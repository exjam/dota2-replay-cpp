#pragma once
#include <cstdint>
#include "networkclass.h"

namespace dota
{

struct CFuncOccluder
{
   uint32_t m_bActive;
   uint32_t m_nOccluderIndex;
};

DeclareNetworkClass(CFuncOccluder);

}
