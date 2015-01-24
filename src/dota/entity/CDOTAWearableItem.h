#pragma once
#include <cstdint>
#include "clientclass.h"
#include "CEconWearable.h"

namespace dota
{

struct CDOTAWearableItem : public CEconWearable
{
   uint32_t m_bOwnerModelChanged;
};

DeclareClientClass(CDOTAWearableItem);

}
