#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CEconWearable.h"

namespace dota
{

struct CTFWearableItem : public CEconWearable
{
};

DeclareNetworkClass(CTFWearableItem);

}
