#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseAnimating.h"

namespace dota
{

struct DT_ScriptCreatedAttribute
{
   uint32_t m_iAttributeDefinitionIndex;
   uint32_t m_iRawValue32;
};

struct DT_AttributeList
{
   DT_ScriptCreatedAttribute m_Attributes[15];
};

struct DT_ScriptCreatedItem
{
   uint32_t m_iItemDefinitionIndex;
   int32_t m_iEntityLevel;
   uint32_t m_iItemIDHigh;
   uint32_t m_iItemIDLow;
   uint32_t m_iAccountID;
   int32_t m_iEntityQuality;
   uint32_t m_bInitialized;
   DT_AttributeList m_AttributeList;
};

struct DT_AttributeContainer
{
   uint32_t m_hOuter;
   uint32_t m_ProviderType;
   uint32_t m_iReapplyProvisionParity;
   DT_ScriptCreatedItem m_Item;
};

struct CBaseAttributableItem : public CBaseAnimating
{
   DT_AttributeContainer m_AttributeManager;
};

DeclareClientStruct(DT_ScriptCreatedAttribute);
DeclareClientStruct(DT_AttributeList);
DeclareClientStruct(DT_ScriptCreatedItem);
DeclareClientStruct(DT_AttributeContainer);
DeclareClientClass(CBaseAttributableItem);

}
