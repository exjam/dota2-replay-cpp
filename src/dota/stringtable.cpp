#include <deque>

#include "bitstream.h"
#include "demoparser.h"
#include "util.h"

namespace dota
{

static const unsigned MAX_STRING_SIZE = 0x400;
static const unsigned STRING_HISTORY_SIZE = 32;

bool DemoParser::parseStringTable(StringTable &table, BitStream &in, std::size_t entries)
{
   auto indexBits = getRequiredBits(table.maxEntries);
   auto history = std::deque<std::string> {};
   auto index = -1;
   auto format = in.readBit();

   for (std::size_t i = 0; i < entries; ++i) {
      auto strData = std::string {};
      auto userData = std::string {};

      // Read index
      if (in.readBit()) {
         index++;
      } else {
         index = in.read<uint32_t>(indexBits);
      }

      // Read str_data
      if (in.readBit()) {
         if (format) {
            assert(!in.readBit());
         }

         if (in.readBit()) {
            auto historyIndex = in.read<std::size_t>(5);
            auto length = in.read<std::size_t>(5);

            if (historyIndex > history.size()) {
               strData = in.readNullTerminatedString(MAX_STRING_SIZE);
            } else {
               assert(length <= history[historyIndex].size());
               strData = history[historyIndex].substr(0, length);
               strData += in.readNullTerminatedString(MAX_STRING_SIZE);
            }
         } else {
            strData = in.readNullTerminatedString(MAX_STRING_SIZE);
         }

         if (history.size() >= STRING_HISTORY_SIZE) {
            history.pop_front();
         }

         history.emplace_back(strData);
      }

      // Read user_data
      if (in.readBit()) {
         auto length = table.userDataSizeBits;

         if (!table.userDataFixedSize) {
            length = in.read<std::size_t>(14) * 8;
         }

         userData = in.readBits(length);
      }

      table.setEntry(index, strData, userData);
   }

   table.lastUpdate = mTick;
   return true;
}

}
