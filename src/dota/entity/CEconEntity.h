#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseAttributableItem.h"
#include "CBaseFlex.h"

namespace dota
{

struct CEconEntity : public CBaseFlex
{
   DT_AttributeContainer m_AttributeManager;
};

DeclareClientClass(CEconEntity);

}
