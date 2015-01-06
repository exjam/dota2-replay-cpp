#include "binarystream.h"
#include "demoparser.h"

bool DemoParser::parse(BinaryStream &in)
{
   auto header = in.readString(8);
   header.resize(7);

   if (header.compare("PBUFDEM") != 0) {
      return 0;
   }

   // Read CDemoFileInfo
   auto offset = in.read<uint32_t>();
   auto pos = in.tell();
   in.seek(offset);
   parseMessage(in);

   // Read game messages
   in.seek(pos);

   for (unsigned i = 0; i < 1000; ++i) {
      parseMessage(in);
   }

   return true;
}
