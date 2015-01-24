#pragma once
#include <cstdint>
#include "clientclass.h"

namespace dota
{

struct CDOTA_DataNonSpectator
{
   uint32_t m_iReliableGold[10];
   uint32_t m_iUnreliableGold[10];
   int32_t m_iStartingPositions[30];
};

DeclareClientClass(CDOTA_DataNonSpectator);

}
