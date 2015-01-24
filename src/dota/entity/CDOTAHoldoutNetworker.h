#pragma once
#include <cstdint>
#include "clientclass.h"

namespace dota
{

struct CDOTAHoldoutNetworker
{
   float m_flPrepTimeLeft;
   int32_t m_nWaveEnemyCount;
   int32_t m_nCurrentEnemyCount;
   int32_t m_nNumberOfRounds;
   int32_t m_nRoundNumber;
   uint32_t m_bIsHeroRespawnEnabled;
   int32_t m_nGoldBagsExpired;
};

DeclareClientClass(CDOTAHoldoutNetworker);

}
