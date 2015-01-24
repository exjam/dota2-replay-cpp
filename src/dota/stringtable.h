#pragma once
#include <map>
#include <string>
#include <vector>
#include "types.h"

namespace dota
{

struct StringTable
{
   struct Entry
   {
      std::string strData;
      std::string userData;
   };

   std::size_t id;
   std::string name;
   std::size_t maxEntries;
   std::size_t userDataSize;
   std::size_t userDataSizeBits;
   bool userDataFixedSize;
   std::size_t flags;
   std::vector<Entry> entries;
   std::map<std::string, Entry*> keyMap;
   Tick lastUpdate;

   Entry *findEntry(std::string key)
   {
      auto itr = keyMap.find(key);

      if (itr != keyMap.end()) {
         return itr->second;
      } else {
         return nullptr;
      }
   }

   void setEntry(int index, std::string strData, std::string userData)
   {
      auto &entry = entries[index];

      if (entry.strData.size()) {
         keyMap.erase(entry.strData);
      }

      entry.strData = std::move(strData);
      entry.userData = std::move(userData);

      if (entry.strData.size() && entry.userData.size()) {
         keyMap[entry.strData] = &entry;
      }
   }
};

}
