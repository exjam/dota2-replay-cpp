#pragma once
#include <cstdint>
#include <cassert>

class BitView
{
   using WordType = uint32_t;
   static const auto WordBytes = sizeof(WordType);
   static const auto WordBits = WordBytes * 8;

public:
   BitView(const char *buffer, size_t size) :
      mBuffer(buffer),
      mSize(size),
      mPosition(0)
   {
      grabNextWord();
   }

   uint32_t readBit()
   {
      auto value = mCurrentWord & 1;
      consumeBits(1);
      return value;
   }

   void readBits(void *buffer, size_t bits)
   {
      auto out = reinterpret_cast<uint8_t *>(buffer);

      // Align output to dword boundary
      while ((reinterpret_cast<size_t>(out) & 3) && bits >= 8) {
         *out = readUint32(8);
         out += 1;
         bits -= 8;
      }

      // Read dwords
      while (bits >= 32) {
         *reinterpret_cast<uint32_t*>(out) = readUint32(32);
         out += 4;
         bits -= 32;
      }

      // Read remaining bytes
      while ((reinterpret_cast<size_t>(out)& 3) && bits >= 8) {
         *out = readUint32(8);
         out += 1;
         bits -= 8;
      }

      // Read remaining bits
      if (bits) {
         *out = readUint32(bits);
      }
   }

   size_t readString(char *buffer, size_t length)
   {
      for (auto i = 0u; i < length; ++i) {
         auto val = readUint32(8);

         if (!val) {
            length = i;
            break;
         }

         buffer[i] = val;
      }

      buffer[length] = 0;
      return length;
   }

   uint32_t readVarUint32()
   {
      auto value = uint32_t { 0 };
      auto byte = 0u;
      auto shift = 0u;

      do {
         byte = readUint32(8);
         value |= (byte & 0x7f) << shift;
         shift += 7;
      } while (byte & 0x80);

      return value;
   }

   uint64_t readVarUint64()
   {
      auto value = uint64_t { 0 };
      auto byte = uint64_t { 0 };
      auto shift = 0u;

      do {
         byte = readUint64(8);
         value |= (byte & 0x7f) << shift;
         shift += 7;
      } while (byte & 0x80);

      return value;
   }

   uint32_t readUint32(size_t bits)
   {
      uint32_t value;

      if (bits <= mBitsRemaining) {
         // Read from current dword
         value = mCurrentWord & ((1ull << bits) - 1);
         consumeBits(bits);
      } else {
         // Read first dword
         auto read = mBitsRemaining;
         bits -= read;
         value = mCurrentWord;
         consumeBits(read);

         // Read second dword
         value |= (mCurrentWord & ((1ull << bits) - 1)) << read;
         consumeBits(bits);
      }

      return value;
   }

   uint64_t readUint64(size_t bits)
   {
      uint64_t value;

      if (bits <= mBitsRemaining) {
         // Read from current dword
         value = mCurrentWord & ((1ull << bits) - 1);
         consumeBits(bits);
      } else {
         // Read first dword
         auto read = mBitsRemaining;
         bits -= read;
         value = mCurrentWord;
         consumeBits(mBitsRemaining);

         // Read middle dwords
         while (bits > mBitsRemaining) {
            value |= mCurrentWord << read;
            bits -= mBitsRemaining;
            read += mBitsRemaining;
            consumeBits(mBitsRemaining);
         }

         // Read final dword
         value |= (mCurrentWord & ((1ull << bits) - 1)) << read;
         consumeBits(bits);
      }

      return value;
   }

   int32_t readInt32(size_t bits)
   {
      // Read as uint32 and sign extend
      auto value = static_cast<int32_t>(readUint32(bits));
      return (value << (32 - bits)) >> (32 - bits);
   }

   int64_t readInt64(size_t bits)
   {
      // Read as uint64 and sign extend
      auto value = static_cast<int64_t>(readUint64(bits));
      return (value << (64 - bits)) >> (64 - bits);
   }

   float readFloat()
   {
      auto value = readUint32(32);
      return *(reinterpret_cast<float*>(&value));
   }

   size_t getBufferPosition()
   {
      return mPosition;
   }

   size_t getBitPosition()
   {
      return WordBits - mBitsRemaining;
   }

   size_t getBufferSize()
   {
      return mSize;
   }

protected:
   void grabNextWord()
   {
      auto readBytes = WordBytes;

      if (mPosition + WordBytes <= mSize) {
         mCurrentWord = *reinterpret_cast<const WordType*>(mBuffer + mPosition);
      } else {
         readBytes = mSize - mPosition;

         if (readBytes >= 2) {
            mCurrentWord = *reinterpret_cast<const uint16_t*>(mBuffer + mPosition);
         } else if (readBytes == 1) {
            mCurrentWord = *reinterpret_cast<const uint8_t*>(mBuffer + mPosition);
         } else {
            assert(0 && "Read past end of buffer!");
         }
      }

      // Read word
      mBitsRemaining = readBytes * 8;
      mPosition += readBytes;
   }

   void consumeBits(size_t bits)
   {
      mCurrentWord >>= bits;
      mBitsRemaining -= bits;

      if (mBitsRemaining == 0) {
         grabNextWord();
      }
   }

private:
   const char *mBuffer;
   size_t mSize;
   size_t mPosition;

   WordType mCurrentWord;
   size_t mBitsRemaining;
};
