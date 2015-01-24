#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct DT_ProxyToggle_ProxiedData
{
   int32_t m_WithProxy;
};

struct CTest_ProxyToggle_Networkable : public CBaseEntity
{
   DT_ProxyToggle_ProxiedData blah;
};

DeclareClientStruct(DT_ProxyToggle_ProxiedData);
DeclareClientClass(CTest_ProxyToggle_Networkable);

}
