#pragma once
#include <cstdint>
#include "networkclass.h"

namespace dota
{

struct CInfoOverlayAccessor
{
   uint32_t m_iTextureFrameIndex;
   uint32_t m_iOverlayID;
};

DeclareNetworkClass(CInfoOverlayAccessor);

}
