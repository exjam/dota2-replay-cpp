#pragma once
#include <cstdint>
#include "networkclass.h"

namespace dota
{

struct CRagdollManager
{
   int32_t m_iCurrentMaxRagdollCount;
};

DeclareNetworkClass(CRagdollManager);

}
