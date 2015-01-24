#pragma once
#include <cstdint>
#include "clientclass.h"

namespace dota
{

struct CInfoOverlayAccessor
{
   uint32_t m_iTextureFrameIndex;
   uint32_t m_iOverlayID;
};

DeclareClientClass(CInfoOverlayAccessor);

}
