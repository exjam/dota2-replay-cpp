#include <deque>

#include "bitview.h"
#include "demoparser.h"
#include "util.h"

#include "proto/demo.pbsl.h"

namespace dota
{

static const unsigned STRING_HISTORY_SIZE = 32;

bool DemoParser::handleDemoStringTables(const CDemoStringTables &stringTables)
{
   for (auto i = 0u; i < stringTables.tables.size(); ++i) {
      auto &table = stringTables.tables[i];
      auto itr = mStringTables.find(table.table_name.to_string());
      assert(itr != mStringTables.end());
      auto &stringTable = itr->second;

      for (auto j = 0u; j < table.items.size(); ++j) {
         auto &item = table.items[j];
         auto &entry = stringTable.entries[j];

         // Remove from keymap
         if (entry.strData) {
            stringTable.keyMap.erase(entry.strData.toStdString());
         }

         // Set values
         entry.strData = item.str;
         entry.userData = item.data;

         // Add to keymap
         if (entry.strData && entry.userData) {
            stringTable.keyMap[entry.strData.toStdString()] = &entry;
         }
      }

      stringTable.lastUpdate = mTick;
   }

   return true;
}

bool DemoParser::parseStringTable(StringTable &table, BitView &in, std::size_t entries)
{
   auto indexBits = getRequiredBits(table.maxEntries);
   auto history = std::deque<const char*> {};
   auto index = -1;
   auto format = in.readBit();

   for (std::size_t i = 0; i < entries; ++i) {
      // Read index
      if (in.readBit()) {
         index++;
      } else {
         index = in.readUint32(indexBits);
      }

      // Cleanup old entry
      auto &entry = table.entries[index];

      if (entry.strData) {
         table.keyMap.erase(entry.strData.toStdString());
      }

      // Read str_data
      if (in.readBit()) {
         if (format) {
            assert(!in.readBit());
         }

         if (in.readBit()) {
            auto historyIndex = in.readUint32(5);
            auto length = in.readUint32(5);

            if (historyIndex > history.size()) {
               in.readString(entry.strData.data(), entry.strData.bufferSize());
            } else {
               strncpy_s(entry.strData.data(), entry.strData.bufferSize(), history[historyIndex], length);
               in.readString(entry.strData.data() + entry.strData.size(), entry.strData.bufferSize() - entry.strData.size());
            }
         } else {
            in.readString(entry.strData.data(), entry.strData.bufferSize());
         }

         if (history.size() >= STRING_HISTORY_SIZE) {
            history.pop_front();
         }

         history.emplace_back(entry.strData.data());
      }

      // Read user_data
      if (in.readBit()) {
         auto length = table.userDataSizeBits;

         if (!table.userDataFixedSize) {
            length = in.readUint32(14) * 8;
         }

         entry.userData.resize(static_cast<std::size_t>(std::ceil(length / 8.0)));
         in.readBits(entry.userData.data(), length);
      }

      // Add to keyMap
      if (entry.strData && entry.userData) {
         table.keyMap[entry.strData.toStdString()] = &entry;
      }
   }

   table.lastUpdate = mTick;
   return true;
}

}
