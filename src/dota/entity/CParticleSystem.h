#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector3f.h"
#include <string>

namespace dota
{

struct CParticleSystem
{
   Vector3f m_vecOrigin;
   float m_flStartTime;
   uint32_t m_iEffectIndex;
   uint32_t m_bActive;
   uint32_t m_hOwnerEntity;
   uint32_t moveparent;
   uint32_t m_iParentAttachment;
   Vector3f m_angRotation;
   uint32_t m_nStopType;
   std::string m_szSnapshotFileName;
   Vector3f m_vServerControlPoints[4];
   uint32_t m_iServerControlPointAssignments[4];
   uint32_t m_hControlPointEnts[64];
   uint32_t m_iControlPointParents[64];
};

DeclareClientClass(CParticleSystem);

}
