#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseTempEntity.h"

namespace dota
{

struct CTEFizz : public CBaseTempEntity
{
   uint32_t m_nEntity;
   int32_t m_nModelIndex;
   uint32_t m_nDensity;
   int32_t m_nCurrent;
};

DeclareClientClass(CTEFizz);

}
