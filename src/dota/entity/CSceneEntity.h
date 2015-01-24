#pragma once
#include <cstdint>
#include "clientclass.h"

namespace dota
{

struct CSceneEntity
{
   uint32_t m_nSceneStringIndex;
   uint32_t m_bIsPlayingBack;
   uint32_t m_bPaused;
   uint32_t m_bMultiplayer;
   float m_flForceClientTime;
   uint32_t m_hActorList[16];
};

DeclareClientClass(CSceneEntity);

}
