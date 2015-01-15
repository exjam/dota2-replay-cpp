#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector3f.h"
#include <string>

namespace dota
{

struct DT_CollisionProperty
{
   Vector3f m_vecMins;
   Vector3f m_vecMaxs;
   uint32_t m_nSolidType;
   uint32_t m_usSolidFlags;
   uint32_t m_nSurroundType;
   uint32_t m_triggerBloat;
   Vector3f m_vecSpecifiedSurroundingMins;
   Vector3f m_vecSpecifiedSurroundingMaxs;
};

struct DT_AnimTimeMustBeFirst
{
   uint32_t m_flAnimTime;
};

struct CBaseEntity
{
   DT_AnimTimeMustBeFirst AnimTimeMustBeFirst;
   uint32_t m_flSimulationTime;
   float m_flCreateTime;
   uint32_t m_ubInterpolationFrame;
   uint32_t m_cellbits;
   uint32_t m_cellX;
   uint32_t m_cellY;
   uint32_t m_cellZ;
   Vector3f m_vecOrigin;
   int32_t m_nModelIndex;
   DT_CollisionProperty m_Collision;
   uint32_t m_nRenderFX;
   uint32_t m_nRenderMode;
   uint32_t m_fEffects;
   uint32_t m_clrRender;
   int32_t m_iTeamNum;
   uint32_t m_CollisionGroup;
   float m_flElasticity;
   float m_flShadowCastDistance;
   uint32_t m_hOwnerEntity;
   uint32_t m_hEffectEntity;
   uint32_t moveparent;
   uint32_t m_iParentAttachment;
   std::string m_iName;
   uint32_t movetype;
   uint32_t movecollide;
   Vector3f m_angRotation;
   uint32_t m_iTextureFrameIndex;
   uint32_t m_bSimulatedEveryTick;
   uint32_t m_bAnimatedEveryTick;
   uint32_t m_bAlternateSorting;
   float m_fadeMinDist;
   float m_fadeMaxDist;
   float m_flFadeScale;
   uint32_t m_nMinCPULevel;
   uint32_t m_nMaxCPULevel;
   uint32_t m_nMinGPULevel;
   uint32_t m_nMaxGPULevel;
};

DeclareNetworkStruct(DT_CollisionProperty);
DeclareNetworkStruct(DT_AnimTimeMustBeFirst);
DeclareNetworkClass(CBaseEntity);

}
