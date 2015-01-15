#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector3f.h"
#include "CBaseParticleEntity.h"

namespace dota
{

struct CSmokeStack : public CBaseParticleEntity
{
   float m_SpreadSpeed;
   float m_Speed;
   float m_StartSize;
   float m_EndSize;
   float m_Rate;
   float m_JetLength;
   uint32_t m_bEmit;
   float m_flBaseSpread;
   float m_flRollSpeed;
   struct {
      Vector3f m_vPos;
      Vector3f m_vColor;
      float m_flIntensity;
   } m_DirLight;
   struct {
      Vector3f m_vPos;
      Vector3f m_vColor;
      float m_flIntensity;
   } m_AmbientLight;
   Vector3f m_vWind;
   float m_flTwist;
   uint32_t m_iMaterialModel;
};

DeclareNetworkClass(CSmokeStack);

}
