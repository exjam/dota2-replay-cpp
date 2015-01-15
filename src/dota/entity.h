#pragma once
#include <vector>
#include "propertyvariant.h"

namespace dota
{

struct EntityClass;

enum class EntityPVS
{
   Preserve,
   Leave,
   Enter,
   Delete
};

struct EntityState {
   std::vector<PropertyVariant> properties;
};

struct Entity
{
   uint32_t serial = 0;
   EntityPVS pvs;
   EntityState state;
   EntityClass *classInfo = nullptr;
};
}
