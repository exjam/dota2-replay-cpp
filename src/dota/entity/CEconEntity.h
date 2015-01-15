#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseAttributableItem.h"
#include "CBaseFlex.h"

namespace dota
{

struct CEconEntity : public CBaseFlex
{
   DT_AttributeContainer m_AttributeManager;
};

DeclareNetworkClass(CEconEntity);

}
