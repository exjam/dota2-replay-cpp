#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector3f.h"
#include <vector>
#include "CBaseAnimating.h"

namespace dota
{

struct CRagdollProp : public CBaseAnimating
{
   std::vector<Vector3f> m_ragAngles;
   std::vector<Vector3f> m_ragPos;
   uint32_t m_hUnragdoll;
   float m_flBlendWeight;
   int32_t m_nOverlaySequence;
};

DeclareClientClass(CRagdollProp);

}
