#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CBaseToggle : public CBaseEntity
{
};

DeclareNetworkClass(CBaseToggle);

}
