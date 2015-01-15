#pragma once
#include <map>
#include <string>
#include <vector>
#include "property.h"

namespace dota
{

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

}
