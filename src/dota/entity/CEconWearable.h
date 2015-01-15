#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CEconEntity.h"

namespace dota
{

struct CEconWearable : public CEconEntity
{
};

DeclareNetworkClass(CEconWearable);

}
