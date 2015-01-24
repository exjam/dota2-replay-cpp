#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector3f.h"

namespace dota
{

struct CFogController
{
   struct {
      uint32_t enable;
      uint32_t blend;
      Vector3f dirPrimary;
      uint32_t colorPrimary;
      uint32_t colorSecondary;
      float start;
      float end;
      float maxdensity;
      float farz;
      uint32_t colorPrimaryLerpTo;
      uint32_t colorSecondaryLerpTo;
      float startLerpTo;
      float endLerpTo;
      float maxdensityLerpTo;
      float lerptime;
      float duration;
      float HDRColorScale;
      uint32_t m_bNoReflectionFog;
   } m_fog;
};

DeclareClientClass(CFogController);

}
