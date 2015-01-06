#include "demoparser.h"
#include <deque>
#include "bitstream.h"
#include "util.h"

static const unsigned STRING_HISTORY_SIZE = 32;

bool DemoParser::parseStringTable(StringTable &table, BitStream &in, std::size_t entries)
{
   auto indexBits = getRequiredBits(table.maxEntries);
   auto history = std::deque<std::string> {};
   auto index = -1;
   auto format = in.readBit();

   for (std::size_t i = 0; i < entries; ++i) {
      // Read index
      if (in.readBit()) {
         index++;
      } else {
         index = in.read<uint32_t>(indexBits);
      }

      auto &entry = table.entries[index];

      // Read str_data
      if (in.readBit()) {
         assert(!(format && in.readBit()));

         if (in.readBit()) {
            auto strIndex = in.read<std::size_t>(5);
            auto strLength = in.read<std::size_t>(5);
            entry.strData = history[strIndex].substr(0, strLength);
            entry.strData += in.readNullTerminatedString();
         } else {
            entry.strData = in.readNullTerminatedString();
         }

         if (history.size() >= STRING_HISTORY_SIZE) {
            history.pop_front();
         }

         history.emplace_back(entry.strData);
      }

      // Read user_data
      if (in.readBit()) {
         auto length = table.userDataSizeBits;

         if (!table.userDataFixedSize) {
            length = in.read<std::size_t>(14) * 8;
         }

         entry.userData = in.readBits(length);
      }

      if (entry.strData.size() && entry.userData.size()) {
         table.keyMap[entry.strData] = &entry;
      }
   }

   return true;
}
