#pragma once
#include <cassert>
#include <cstdint>
#include <istream>
#include <string>
#include <vector>

class BinaryStream
{
public:
   BinaryStream(std::istream &stream) :
      mStream(stream)
   {
   }

   void seek(std::istream::pos_type pos)
   {
      mStream.seekg(pos);
   }

   std::istream::pos_type tell()
   {
      return mStream.tellg();
   }

   bool eof()
   {
      return mStream.peek() == EOF;
   }

   template<typename T>
   T read()
   {
      assert(!eof());
      T value = 0;
      mStream.read(reinterpret_cast<char*>(&value), sizeof(value));
      return value;
   }

   template<typename T>
   T readVarint()
   {
      T value = 0;

      for (unsigned bytes = 0, byte = 0x80; bytes < 9 && (byte & 0x80); ++bytes) {
         byte = read<uint8_t>();
         value |= (byte & 0x7f) << (7 * bytes);
      }

      return value;
   }

   std::vector<uint8_t> readBytes(std::size_t length)
   {
      std::vector<uint8_t> value;

      if (length) {
         value.resize(length);
         mStream.read(reinterpret_cast<char*>(value.data()), length);
      }

      return value;
   }

   std::string readString(std::size_t length)
   {
      std::string value;

      if (length) {
         value.resize(length);
         mStream.read(&value[0], length);
      }

      return value;
   }

private:
   std::istream &mStream;
};
