#pragma once
#include <map>
#include <string>
#include <vector>
#include "property.h"

namespace dota
{

struct SendTable
{
   const Property *findProperty(const std::string &name) const
   {
      for (auto &&prop : properties) {
         if (prop.varName.compare(name) == 0) {
            return &prop;
         }
      }

      return nullptr;
   }

   bool needsDecode;
   std::string name;
   std::vector<Property> properties;
};

}
