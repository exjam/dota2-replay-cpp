#pragma once
#include <map>
#include <string>
#include <vector>

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
};

}
