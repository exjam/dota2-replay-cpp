#pragma once
#include <string>
#include <vector>
#include <map>
#include "property.h"

struct SendTable
{
   bool needsDecode;
   std::string name;

   std::vector<Property> properties;

   struct ExcludeProperty
   {
      std::string table;
      std::string prop;
   };
};
