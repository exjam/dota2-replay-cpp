#pragma once
#include <cstdint>
#include "clientclass.h"
#include <string>
#include "CBaseEntity.h"

namespace dota
{

struct CEnvProjectedTexture : public CBaseEntity
{
   uint32_t m_hTargetEntity;
   uint32_t m_bState;
   uint32_t m_bAlwaysUpdate;
   float m_flLightFOV;
   uint32_t m_bEnableShadows;
   uint32_t m_bSimpleProjection;
   uint32_t m_bLightOnlyTarget;
   uint32_t m_bLightWorld;
   uint32_t m_bCameraSpace;
   float m_flBrightnessScale;
   uint32_t m_LightColor;
   float m_flFarZ;
   float m_flColorTransitionTime;
   float m_flAmbient;
   std::string m_SpotlightTextureName;
   int32_t m_nSpotlightTextureFrame;
   float m_flNearZ;
   uint32_t m_nShadowQuality;
   float m_flProjectionSize;
   float m_flRotation;
};

DeclareClientClass(CEnvProjectedTexture);

}
