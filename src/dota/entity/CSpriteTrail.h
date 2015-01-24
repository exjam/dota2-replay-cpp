#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector3f.h"
#include "CSprite.h"

namespace dota
{

struct CSpriteTrail : public CSprite
{
   float m_flLifeTime;
   float m_flStartWidth;
   float m_flEndWidth;
   float m_flStartWidthVariance;
   float m_flTextureRes;
   float m_flMinFadeLength;
   Vector3f m_vecSkyboxOrigin;
   float m_flSkyboxScale;
};

DeclareClientClass(CSpriteTrail);

}
