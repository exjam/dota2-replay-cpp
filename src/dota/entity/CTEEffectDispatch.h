#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector3f.h"
#include "CBaseTempEntity.h"

namespace dota
{

struct DT_EffectData
{
   struct {
      float x;
      float y;
      float z;
   } m_vOrigin;
   struct {
      float x;
      float y;
      float z;
   } m_vStart;
   Vector3f m_vAngles;
   Vector3f m_vNormal;
   uint32_t m_fFlags;
   float m_flMagnitude;
   float m_flScale;
   int32_t m_nAttachmentIndex;
   uint32_t m_nSurfaceProp;
   uint32_t m_iEffectName;
   uint32_t m_nMaterial;
   uint32_t m_nDamageType;
   uint32_t m_nHitBox;
   uint32_t entindex;
   uint32_t m_nOtherEntIndex;
   uint32_t m_nColor;
   float m_flRadius;
};

struct CTEEffectDispatch : public CBaseTempEntity
{
   DT_EffectData m_EffectData;
};

DeclareNetworkStruct(DT_EffectData);
DeclareNetworkClass(CTEEffectDispatch);

}
