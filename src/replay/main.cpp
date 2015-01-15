#include <iostream>
#include <fstream>

#include "binarystream.h"
#include "demoparser.h"

int main()
{
   auto file = std::ifstream { "1151921935.dem", std::ifstream::binary };
   auto in = BinaryStream { file };
   auto demo = dota::DemoParser {};
   demo.parse(in);
   std::cout << "Finished parse, destructor takes years!" << std::endl;
   return 0;
}
