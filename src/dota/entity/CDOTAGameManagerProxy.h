#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseEntity.h"

namespace dota
{

struct DT_DOTA_GameManager
{
   uint32_t m_StableHeroAvailable[128];
   uint32_t m_CurrentHeroAvailable[128];
   uint32_t m_CulledHeroes[128];
};

struct CDOTAGameManagerProxy : public CBaseEntity
{
   DT_DOTA_GameManager dota_gamemanager_data;
};

DeclareNetworkStruct(DT_DOTA_GameManager);
DeclareNetworkClass(CDOTAGameManagerProxy);

}
