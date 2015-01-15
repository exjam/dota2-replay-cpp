#pragma once
#include <map>
#include <string>
#include <vector>

#include "sendtable.h"

namespace dota
{

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

struct EntityClass
{
   std::size_t id;
   std::string name;
   std::string tableName;
   SendTable *sendTable = nullptr;
   ReceiveTable receiveTable;

   std::string getBaseClass() const
   {
      if (sendTable) {
         for (auto &&prop : sendTable->properties) {
            if (prop.varName.compare("baseclass") == 0) {
               return prop.dtName;
            }
         }
      }

      return {};
   }
};

}
