#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CDOTAMinimapBoundary : public CBaseEntity
{
};

DeclareNetworkClass(CDOTAMinimapBoundary);

}
