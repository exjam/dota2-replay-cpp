#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseTempEntity.h"

namespace dota
{

struct CTEFoundryHelpers : public CBaseTempEntity
{
   int32_t m_iEntity;
};

DeclareNetworkClass(CTEFoundryHelpers);

}
