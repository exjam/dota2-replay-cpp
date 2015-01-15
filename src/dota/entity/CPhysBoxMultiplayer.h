#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CPhysBox.h"

namespace dota
{

struct CPhysBoxMultiplayer : public CPhysBox
{
   uint32_t m_iPhysicsMode;
   float m_fMass;
};

DeclareNetworkClass(CPhysBoxMultiplayer);

}
