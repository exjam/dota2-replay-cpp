#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CHandleTest : public CBaseEntity
{
   uint32_t m_Handle;
   int32_t m_bSendHandle;
};

DeclareClientClass(CHandleTest);

}
