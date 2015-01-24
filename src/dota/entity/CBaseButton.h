#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CBaseToggle.h"

namespace dota
{

struct CBaseButton : public CBaseToggle
{
};

DeclareClientClass(CBaseButton);

}
