#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseAnimating.h"

namespace dota
{

struct CEnvParticleScript : public CBaseAnimating
{
   float m_flSequenceScale;
};

DeclareClientClass(CEnvParticleScript);

}
