#pragma once
#include <cstdint>
#include "networkclass.h"
#include "CEconWearable.h"

namespace dota
{

struct CDOTAWearableItem : public CEconWearable
{
   uint32_t m_bOwnerModelChanged;
};

DeclareNetworkClass(CDOTAWearableItem);

}
