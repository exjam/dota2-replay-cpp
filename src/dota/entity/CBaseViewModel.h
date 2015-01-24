#pragma once
#include <cstdint>
#include "clientclass.h"

namespace dota
{

struct CBaseViewModel
{
   int32_t m_nModelIndex;
   uint32_t m_hWeapon;
   int32_t m_nBody;
   int32_t m_nSkin;
   uint32_t m_nSequence;
   uint32_t m_nViewModelIndex;
   float m_flPlaybackRate;
   uint32_t m_fEffects;
   uint32_t m_nAnimationParity;
   uint32_t m_hOwner;
   uint32_t m_nNewSequenceParity;
   uint32_t m_nResetEventsParity;
   uint32_t m_nMuzzleFlashParity;
};

DeclareClientClass(CBaseViewModel);

}
