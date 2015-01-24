#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseTempEntity.h"

namespace dota
{

struct CTEFoundryHelpers : public CBaseTempEntity
{
   int32_t m_iEntity;
};

DeclareClientClass(CTEFoundryHelpers);

}
