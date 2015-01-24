#include <iostream>
#include <set>
#include "clientclass.h"
#include "demoparser.h"

namespace dota
{

struct ExcludeProperty
{
   std::string table;
   std::string prop;
};

using SendTableExclusions = std::vector<ExcludeProperty>;
using ReceiveProperties = std::vector<ReceiveProperty>;
using ReceivePropertyMap = std::map<std::string, ReceiveProperty*>;

static bool
buildHeirarchy(const SendTableMap &sendTableMap,
               const SendTableExclusions &exclusions,
               const SendTable &sendTable,
               ReceiveProperties &properties,
               std::string path);
static bool
buildHeirarchyProperties(const SendTableMap &sendTableMap,
                         const SendTableExclusions &exclusions,
                         const SendTable &sendTable,
                         ReceiveProperties &properties,
                         ReceiveProperties &recvProps,
                         std::string path);

static bool
getExclusions(const SendTableMap &sendTableMap,
              const SendTable &table,
              SendTableExclusions &exclusions)
{
   for (auto &&prop : table.properties) {
      if (prop.isExcluded()) {
         exclusions.push_back({ prop.dtName, prop.varName });
      } else if (prop.isDataTable()) {
         auto itr = sendTableMap.find(prop.dtName);
         assert(itr != sendTableMap.end());
         getExclusions(sendTableMap, itr->second, exclusions);
      }
   }

   return true;
}

static bool
isExcluded(const SendTableExclusions &exclusions,
           std::string table,
           std::string name)
{
   for (auto &&exclusion : exclusions) {
      if (exclusion.table.compare(table) == 0 && exclusion.prop.compare(name) == 0) {
         return true;
      }
   }

   return false;
}

static bool
buildHeirarchy(const SendTableMap &sendTableMap,
               const SendTableExclusions &exclusions,
               const SendTable &sendTable,
               ReceiveProperties &properties,
               std::string path)
{
   auto recvProps = ReceiveProperties {};
   buildHeirarchyProperties(sendTableMap, exclusions, sendTable, properties, recvProps, path);
   properties.insert(properties.end(), recvProps.begin(), recvProps.end());
   return true;
}

static bool
buildHeirarchyProperties(const SendTableMap &sendTableMap,
                         const SendTableExclusions &exclusions,
                         const SendTable &sendTable,
                         ReceiveProperties &properties,
                         ReceiveProperties &recvProps,
                         std::string path)
{
   for (auto &&sendProp : sendTable.properties) {
      if (sendProp.isExcluded() || sendProp.isInsideArray()) {
         continue;
      }

      if (isExcluded(exclusions, sendTable.name, sendProp.varName)) {
         continue;
      }

      if (sendProp.isDataTable()) {
         auto &dtTable = sendTableMap.find(sendProp.dtName)->second;
         if (sendProp.isCollapsible()) {
            buildHeirarchyProperties(sendTableMap, exclusions, dtTable, properties, recvProps, path);
         } else {
            path.append(sendProp.varName);
            path.push_back('.');
            buildHeirarchy(sendTableMap, exclusions, dtTable, properties, path);
            path.resize(path.size() - 1 - sendProp.varName.size());
         }
      } else {
         ReceiveProperty prop;
         prop.sendProp = &sendProp;
         prop.table = &sendTable;
         prop.varName = path + sendProp.varName;
         prop.offset = -1;
         recvProps.push_back(prop);
      }
   }

   return true;
}

static bool
mapClientClass(const SendTableMap &sendTableMap,
               const ClientClassBase *clientClass,
               ReceiveProperties &recvProperties,
               ReceivePropertyMap &recvPropertyMap,
               std::string basePath,
               std::ptrdiff_t baseOffset)
{
   char buffer[256];
   auto &sendTable = sendTableMap.find(clientClass->tableName)->second;

   // Dont forget our base class! faggot!
   if (clientClass->baseClass) {
      mapClientClass(sendTableMap, clientClass->baseClass, recvProperties, recvPropertyMap, "", 0);
   }

   // Map our client-class to our receive-table
   for (auto &kvpair : clientClass->properties) {
      auto &prop = kvpair.second;
      auto offset = baseOffset + prop.offset;
      auto name = basePath + kvpair.first;

      if (prop.arraySize) {
         // Add all arraySize props!
         if (prop.dataTable) {
            // For datatable element type we must recurse in
            for (int i = 0; i < prop.arraySize; ++i) {
               // Find all with name.%04d.
               sprintf_s(buffer, 256, "%s.%04d.", name.c_str(), i);
               mapClientClass(sendTableMap, prop.dataTable, recvProperties, recvPropertyMap, buffer, offset);

               // Find all with name[%d].
               sprintf_s(buffer, 256, "%s[%d].", name.c_str(), i);
               mapClientClass(sendTableMap, prop.dataTable, recvProperties, recvPropertyMap, buffer, offset);
            }
         } else {
            // Array values can be in form name[%d] or name.%04d.
            for (int i = 0; i < prop.arraySize; ++i) {
               sprintf_s(buffer, 256, "%s.%04d", name.c_str(), i);

               auto itr = recvPropertyMap.find(buffer);
               if (itr == recvPropertyMap.end()) {
                  sprintf_s(buffer, 256, "%s[%d]", name.c_str(), i);
                  itr = recvPropertyMap.find(buffer);
               }

               if (itr != recvPropertyMap.end()) {
                  auto recvProp = itr->second;
                  recvProp->offset = prop.elemGetter->getElementPtr(offset, i);
                  recvProp->clientProp = &prop;
               }
            }
         }
      } else {
         auto itr = recvPropertyMap.find(name);

         if (prop.dataTable) {
            // Recurse into data table properties
            auto sendProp = sendTable.findProperty(kvpair.first);

            if (sendProp && sendProp->isCollapsible()) {
               mapClientClass(sendTableMap, prop.dataTable, recvProperties, recvPropertyMap, basePath, offset);
            } else {
               mapClientClass(sendTableMap, prop.dataTable, recvProperties, recvPropertyMap, name + ".", offset);
            }
         } else {
            // This handles prop flag VectorElem stuff
            if (prop.type == PropertyType::Vector || prop.type == PropertyType::VectorXY) {
               itr = recvPropertyMap.find(name + "[0]");
               if (itr != recvPropertyMap.end()) {
                  auto recvProp = itr->second;
                  recvProp->clientProp = &prop;
                  recvProp->offset = offset;
               }

               itr = recvPropertyMap.find(name + "[1]");
               if (itr != recvPropertyMap.end()) {
                  auto recvProp = itr->second;
                  recvProp->offset = offset + sizeof(float);
                  recvProp->clientProp = &prop;
               }

               itr = recvPropertyMap.find(name + "[2]");
               if (itr != recvPropertyMap.end()) {
                  auto recvProp = itr->second;
                  recvProp->offset = offset + 2 * sizeof(float);
                  recvProp->clientProp = &prop;
               }
            }

            itr = recvPropertyMap.find(name);

            if (itr == recvPropertyMap.end()) {
               // Lets try find it with quotes like for "player_array"
               itr = recvPropertyMap.find("\"" + name + "\"");
            }

            if (itr != recvPropertyMap.end()) {
               auto recvProp = itr->second;
               recvProp->offset = offset;
               recvProp->clientProp = &prop;
            }
         }
      }
   }

   return true;
}

static bool sortProperties(ReceiveProperties &properties)
{
   auto priorities = std::set<unsigned> { 64 };
   auto offset = std::size_t { 0 };

   for (auto &&prop : properties) {
      priorities.insert(prop.sendProp->priority);
   }

   for (auto &&priority : priorities) {
      auto hole = offset;
      auto cursor = offset;

      while (cursor < properties.size()) {
         auto &prop = properties[cursor];
         auto sendProp = prop.sendProp;

         if (sendProp->priority == priority || (sendProp->isChangedOften() && priority == 64)) {
            std::iter_swap(properties.begin() + cursor, properties.begin() + hole);
            hole++;
            offset++;
         }

         cursor++;
      }
   }

   return true;
}

bool DemoParser::updateEntityClass(EntityClass &entityClass)
{
   auto &sendTable = *entityClass.sendTable;
   auto &properties = entityClass.properties;
   auto &propertyMap = entityClass.propertyMap;
   auto exclusions = SendTableExclusions {};
   auto &sendTableMap = mSendTables;

   if (!getExclusions(sendTableMap, sendTable, exclusions)) {
      return false;
   }

   if (!buildHeirarchy(sendTableMap, exclusions, sendTable, properties, "")) {
      return false;
   }

   if (!sortProperties(properties)) {
      return false;
   }

   // Add all properties to propertyMap
   for (auto i = 0; i < properties.size(); ++i) {
      propertyMap[properties[i].varName] = &properties[i];
   }

   if (!mapClientClass(sendTableMap, ClientClassList::get(sendTable.name), properties, propertyMap, "", 0)) {
      return false;
   }

   // Debug print fields that dont match up to our client class!
   if (1) {
      bool printedName = false;
      auto size = ClientClassList::get(sendTable.name)->getSize();

      for (auto &&prop : properties) {
         if (prop.offset == -1) {
            // We ignore lengthproxy and lengthprop for now
            if (prop.varName.find("lengthproxy") != std::string::npos) {
               continue;
            }

            if (prop.varName.find("lengthprop") != std::string::npos) {
               continue;
            }

            if (!printedName) {
               std::cout << sendTable.name << std::endl;
               printedName = true;
            }

            std::cout << prop.offset << " " << prop.varName << std::endl;
         }
      }
   }

   return true;
}

}
