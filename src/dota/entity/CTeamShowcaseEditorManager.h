#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector3f.h"
#include <string>
#include "CBaseEntity.h"

namespace dota
{

struct DT_ShowcaseSlot
{
   int32_t nType;
   std::string szName;
   Vector3f vecLocalOrigin;
   Vector3f angLocalAngles;
   uint32_t hEntity;
   uint64_t ulItemID;
   uint32_t bIsOnlySlotOfThisType;
};

struct DT_ShowcaseData
{
   uint32_t m_hRootEntity;
   DT_ShowcaseSlot m_Slots[8];
};

struct CTeamShowcaseEditorManager : public CBaseEntity
{
   int32_t m_nEditorMode;
   int32_t m_nCurEditingSlot;
   DT_ShowcaseData m_Data;
};

DeclareNetworkStruct(DT_ShowcaseSlot);
DeclareNetworkStruct(DT_ShowcaseData);
DeclareNetworkClass(CTeamShowcaseEditorManager);

}
