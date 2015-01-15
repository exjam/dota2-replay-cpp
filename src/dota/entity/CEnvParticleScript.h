#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseAnimating.h"

namespace dota
{

struct CEnvParticleScript : public CBaseAnimating
{
   float m_flSequenceScale;
};

DeclareNetworkClass(CEnvParticleScript);

}
