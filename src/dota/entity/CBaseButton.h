#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CBaseToggle.h"

namespace dota
{

struct CBaseButton : public CBaseToggle
{
};

DeclareNetworkClass(CBaseButton);

}
