#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CPostProcessController : public CBaseEntity
{
   float m_flPostProcessParameters[11];
   uint32_t m_bMaster;
};

DeclareClientClass(CPostProcessController);

}
