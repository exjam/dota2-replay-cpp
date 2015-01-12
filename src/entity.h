#pragma once
#include <vector>
#include "propertyvariant.h"

struct ClassInfo;

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
   ClassInfo *classInfo = nullptr;
};
