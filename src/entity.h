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
   std::size_t id;
   uint32_t serial;
   EntityPVS pvs;
   ClassInfo *classInfo;
   EntityState state;
};
