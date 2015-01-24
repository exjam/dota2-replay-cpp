#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector3f.h"
#include "CPhysicsProp.h"

namespace dota
{

struct CStatueProp : public CPhysicsProp
{
   uint32_t m_hInitBaseAnimating;
   uint32_t m_bShatter;
   int32_t m_nShatterFlags;
   Vector3f m_vShatterPosition;
   Vector3f m_vShatterForce;
};

DeclareClientClass(CStatueProp);

}
