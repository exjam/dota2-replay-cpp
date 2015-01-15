#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CPostProcessController : public CBaseEntity
{
   float m_flPostProcessParameters[11];
   uint32_t m_bMaster;
};

DeclareNetworkClass(CPostProcessController);

}
