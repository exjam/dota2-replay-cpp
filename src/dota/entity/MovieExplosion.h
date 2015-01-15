#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseParticleEntity.h"

namespace dota
{

struct MovieExplosion : public CBaseParticleEntity
{
};

DeclareNetworkClass(MovieExplosion);

}
