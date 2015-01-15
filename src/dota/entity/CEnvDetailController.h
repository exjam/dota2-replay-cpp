#pragma once
#include <cstdint>
#include "networkclass.h"

namespace dota
{

struct CEnvDetailController
{
   float m_flFadeStartDist;
   float m_flFadeEndDist;
};

DeclareNetworkClass(CEnvDetailController);

}
