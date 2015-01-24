#pragma once
#include <cstdint>
#include "clientclass.h"
#include <string>
#include "CBaseEntity.h"

namespace dota
{

struct CTesla : public CBaseEntity
{
   std::string m_SoundName;
   std::string m_iszSpriteName;
};

DeclareClientClass(CTesla);

}
