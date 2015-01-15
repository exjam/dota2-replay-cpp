#include <set>
#include "demoparser.h"

namespace dota
{

using ReceiveTableProperties = std::vector<ReceiveTable::ReceiveProperty>;
using SendTableExclusions = std::vector<SendTable::ExcludeProperty>;

class SendTableFlattener {
   SendTableMap &mSendTables;
   SendTableExclusions mExclusions;

public:
   SendTableFlattener(SendTableMap &sendTables) :
      mSendTables(sendTables)
   {
   }

   bool flattenSendTable(SendTable &sendTable, ReceiveTable &recvTable)
   {
      if (!getExclusions(sendTable)) {
         return false;
      }

      if (!buildHeirarchy(sendTable, recvTable, "")) {
         return false;
      }

      if (!sortProperties(recvTable.properties)) {
         return false;
      }

      for (auto &&prop : recvTable.properties) {
         recvTable.propertyMap[prop.varName] = &prop;
      }

      return true;
   }

   bool getExclusions(SendTable &table)
   {
      for (auto &&prop : table.properties) {
         if (prop.isExcluded()) {
            mExclusions.push_back({ prop.dtName, prop.varName });
         } else if (prop.isDataTable()) {
            auto itr = mSendTables.find(prop.dtName);
            assert(itr != mSendTables.end());
            getExclusions(itr->second);
         }
      }

      return true;
   }

   bool isExcluded(std::string table, std::string name)
   {
      for (auto &&exclusion : mExclusions) {
         if (exclusion.table.compare(table) == 0 && exclusion.prop.compare(name) == 0) {
            return true;
         }
      }

      return false;
   }

   bool buildHeirarchy(SendTable &sendTable, ReceiveTable &recvTable, std::string path = {})
   {
      auto properties = ReceiveTableProperties {};
      buildHeirarchyProperties(sendTable, recvTable, properties, path);
      recvTable.properties.insert(recvTable.properties.end(), properties.begin(), properties.end());
      return true;
   }

   bool buildHeirarchyProperties(SendTable &sendTable, ReceiveTable &recvTable, ReceiveTableProperties &recvProps, std::string path)
   {
      for (auto &&sendProp : sendTable.properties) {
         if (sendProp.isExcluded() || sendProp.isInsideArray()) {
            continue;
         }

         if (isExcluded(sendTable.name, sendProp.varName)) {
            continue;
         }

         if (sendProp.isDataTable()) {
            if (sendProp.isCollapsible()) {
               buildHeirarchyProperties(mSendTables[sendProp.dtName], recvTable, recvProps, path);
            } else {
               path.append(sendProp.varName);
               path.push_back('.');
               buildHeirarchy(mSendTables[sendProp.dtName], recvTable, path);
               path.resize(path.size() - 1 - sendProp.varName.size());
            }
         } else {
            recvProps.push_back({ path + sendProp.varName, &sendTable, &sendProp });
         }
      }

      return true;
   }

   bool sortProperties(ReceiveTableProperties &properties)
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
};

bool DemoParser::flattenSendTable(SendTable &sendTable, ReceiveTable &recvTable)
{
   auto flattener = SendTableFlattener { mSendTables };
   return flattener.flattenSendTable(sendTable, recvTable);
}

}
