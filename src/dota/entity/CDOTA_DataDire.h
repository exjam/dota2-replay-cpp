#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CDOTA_DataNonSpectator.h"

namespace dota
{

struct CDOTA_DataDire : public CDOTA_DataNonSpectator
{
};

DeclareClientClass(CDOTA_DataDire);

}
