#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CPrecipitationBlocker : public CBaseEntity
{
};

DeclareNetworkClass(CPrecipitationBlocker);

}
