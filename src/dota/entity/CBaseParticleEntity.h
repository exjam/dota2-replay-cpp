#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct CBaseParticleEntity : public CBaseEntity
{
};

DeclareNetworkClass(CBaseParticleEntity);

}
