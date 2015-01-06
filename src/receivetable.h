#pragma once
#include <string>
#include <vector>
#include <map>

struct ReceiveTable
{
   struct ReceiveProperty
   {
      std::string varName;
      class SendTable *table;
      class Property *sendProp;
   };

   std::vector<ReceiveProperty> properties;
   std::map<std::string, ReceiveProperty*> propertyMap;
};
