#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CPhysBox.h"

namespace dota
{

struct CPhysBoxMultiplayer : public CPhysBox
{
   uint32_t m_iPhysicsMode;
   float m_fMass;
};

DeclareClientClass(CPhysBoxMultiplayer);

}
