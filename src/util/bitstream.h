#pragma once
#include <algorithm>
#include "binarystream.h"

class BitStream
{
   static uint8_t sBitMask[9];
public:
   BitStream(BinaryStream &stream) :
      mStream(stream),
      mOffset(8),
      mCurrentByte(0)
   {
   }

   uint8_t readBit()
   {
      if (mOffset == 8) {
         mOffset = 0;
         mCurrentByte = mStream.read<uint8_t>();
      }

      return (mCurrentByte >> mOffset++) & 0x1;
   }

   int64_t readVarInt()
   {
      auto value = 0;
      auto byte = 0;
      auto shift = 0;

      do {
         byte = read<uint8_t>(8);
         value |= static_cast<int64_t>(byte & 0x7f) << shift;
         shift += 7;
      } while (byte & 0x80);

      return value;
   }

   std::string readBits(std::size_t bits)
   {
      std::string value;

      while (bits >= 8) {
         value.push_back(read<char>(8));
         bits -= 8;
      }

      value.push_back(read<char>(bits));
      return value;
   }

   std::string readStringLength(std::size_t bytes)
   {
      std::string value;
      char ch;

      while (bytes > 0 && (ch = read<char>(8))) {
         value.push_back(ch);
         bytes--;
      }

      return value;
   }

   std::string readNullTerminatedString(std::size_t max_length = 999999)
   {
      std::string value;
      char ch;

      while ((ch = read<char>(8)) && value.size() < max_length) {
         value.push_back(ch);
      }

      return value;
   }

   std::vector<uint8_t> readBytes(std::size_t bytes)
   {
      std::vector<uint8_t> value;

      while (bytes) {
         value.push_back(read<uint8_t>(8));
         --bytes;
      }

      return value;
   }

   template<typename T>
   T read(std::size_t bits)
   {
      std::size_t read = 0;
      T value = 0;

      while (bits > 0) {
         if (mOffset == 8) {
            mOffset = 0;
            mCurrentByte = mStream.read<uint8_t>();
         }

         std::size_t count = std::min(bits, 8 - mOffset);
         value |= ((mCurrentByte >> mOffset) & sBitMask[count]) << read;
         mOffset += count;
         bits -= count;
         read += count;
      }

      return value;
   }

   template<>
   float read<float>(std::size_t bits)
   {
      union {
         uint32_t uv;
         float fv;
      } aMagicalUnionOfNumbers;

      aMagicalUnionOfNumbers.uv = read<uint32_t>(bits);
      return aMagicalUnionOfNumbers.fv;
   }

   template<>
   int32_t read<int32_t>(std::size_t bits)
   {
      auto value = read<uint32_t>(bits);
      auto mask = 1U << (bits - 1);
      value = (value ^ mask) - mask;
      return value;
   }

   template<>
   int64_t read<int64_t>(std::size_t bits)
   {
      auto value = read<uint64_t>(bits);
      auto mask = 1ULL << (bits - 1);
      value = (value ^ mask) - mask;
      return value;
   }

private:
   std::size_t mOffset;
   uint8_t mCurrentByte;
   BinaryStream mStream;
};
