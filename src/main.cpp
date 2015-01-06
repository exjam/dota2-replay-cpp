#include <fstream>

#include "binarystream.h"
#include "demoparser.h"

int main()
{
   auto file = std::ifstream { "test.dem", std::ifstream::binary };
   auto in = BinaryStream { file };
   auto demo = DemoParser {};
   demo.parse(in);
   return 0;
}
