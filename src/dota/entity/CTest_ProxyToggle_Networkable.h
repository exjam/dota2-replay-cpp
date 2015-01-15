#pragma once
#include <cstdint>
#include "networkclass.h"
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

DeclareNetworkStruct(DT_ProxyToggle_ProxiedData);
DeclareNetworkClass(CTest_ProxyToggle_Networkable);

}
