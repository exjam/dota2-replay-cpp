#pragma once
#include <cstdint>
#include "clientclass.h"

namespace dota
{

struct CFuncOccluder
{
   uint32_t m_bActive;
   uint32_t m_nOccluderIndex;
};

DeclareClientClass(CFuncOccluder);

}
