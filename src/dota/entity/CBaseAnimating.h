#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector3f.h"
#include "CBaseEntity.h"

namespace dota
{

struct DT_ServerAnimationData
{
   float m_flCycle;
};

struct CBaseAnimating : public CBaseEntity
{
   int32_t m_nForceBone;
   Vector3f m_vecForce;
   int32_t m_nSkin;
   int32_t m_nBody;
   uint32_t m_nHitboxSet;
   float m_flModelScale;
   float m_flPoseParameter[24];
   uint32_t m_nSequence;
   float m_flPlaybackRate;
   float m_flEncodedController[4];
   uint32_t m_bClientSideAnimation;
   uint32_t m_bClientSideFrameReset;
   uint32_t m_bClientSideRagdoll;
   uint32_t m_nNewSequenceParity;
   uint32_t m_nResetEventsParity;
   uint32_t m_nMuzzleFlashParity;
   uint32_t m_hLightingOrigin;
   DT_ServerAnimationData serveranimdata;
   float m_flFrozen;
};

DeclareNetworkStruct(DT_ServerAnimationData);
DeclareNetworkClass(CBaseAnimating);

}
