#pragma once
#include <cstdint>
#include "clientclass.h"

namespace dota
{

struct CRagdollManager
{
   int32_t m_iCurrentMaxRagdollCount;
};

DeclareClientClass(CRagdollManager);

}
