#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CDOTA_DataNonSpectator.h"

namespace dota
{

struct CDOTA_DataDire : public CDOTA_DataNonSpectator
{
};

DeclareNetworkClass(CDOTA_DataDire);

}
