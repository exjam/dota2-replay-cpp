#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector3f.h"
#include "CPhysicsProp.h"

namespace dota
{

struct CPhysicsPropMultiplayer : public CPhysicsProp
{
   uint32_t m_iPhysicsMode;
   float m_fMass;
   Vector3f m_collisionMins;
   Vector3f m_collisionMaxs;
};

DeclareNetworkClass(CPhysicsPropMultiplayer);

}
