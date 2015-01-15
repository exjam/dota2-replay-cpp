#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector3f.h"
#include <string>
#include "CBaseEntity.h"

namespace dota
{

struct CEnvDeferredLight : public CBaseEntity
{
   uint32_t m_LightColor;
   float m_flIntensity;
   float m_flLightSize;
   float m_flSpotFoV;
   Vector3f m_vLightDirection;
   float m_flStartFalloff;
   float m_flDistanceFalloff;
   int32_t m_nFlags;
   std::string m_ProjectedTextureName;
};

DeclareNetworkClass(CEnvDeferredLight);

}
