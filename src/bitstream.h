#pragma once

#include "binarystream.h"

class BitStream
{
   static unsigned char sBitMask[9];
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

   template<typename T>
   T read(unsigned bits)
   {
      unsigned read;
      T value;

      while (bits > 0) {
         if (mOffset == 8) {
            mOffset = 0;
            mCurrentByte = mStream.read<uint8_t>();
         }

         unsigned count = std::min(bits, 8 - mOffset);
         value |= ((mCurrentByte >> mOffset) & sBitMask[count]) << read;
         mOffset += count;
         bits -= count;
         read += count;
      }

      return value;
   }

private:
   unsigned mOffset;
   uint8_t mCurrentByte;
   BinaryStream mStream;
};
