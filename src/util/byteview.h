#pragma once
#include <cassert>
#include <cstdint>
#include <string>
#include <vector>
#include <string_view.h>

class ByteView
{
public:
   ByteView(const char *buffer, size_t size) :
      mBuffer(buffer),
      mSize(size),
      mPosition(0)
   {
   }

   ByteView(const std::string &str) :
      mBuffer(str.c_str()),
      mSize(str.size()),
      mPosition(0)
   {
   }

   ByteView(const std::string_view &str) :
      mBuffer(str.data()),
      mSize(str.size()),
      mPosition(0)
   {
   }

   void seek(size_t pos)
   {
      mPosition = pos;
   }

   void skip(size_t bytes)
   {
      mPosition += bytes;
   }

   std::size_t tell() const
   {
      return mPosition;
   }

   bool eof() const
   {
      return mPosition == mSize;
   }

   template<typename ValueType>
   ValueType read()
   {
      assert(checkRemainingSpace(sizeof(ValueType)));
      auto pos = mPosition;
      mPosition += sizeof(ValueType);
      return *reinterpret_cast<const ValueType*>(mBuffer + pos);
   }

   uint32_t readVarint32()
   {
      auto ptr = reinterpret_cast<const uint8_t*>(mBuffer + mPosition);
      auto value = 0u;
      auto bytes = 0u;

      do {
         value |= (*ptr & 0x7f) << (bytes * 7u);
         bytes++;
      } while (*(ptr++) & 0x80 && bytes <= 5);

      mPosition += bytes;
      return value;
   }

   uint64_t readVarint64()
   {
      auto ptr = reinterpret_cast<const uint8_t*>(mBuffer + mPosition);
      auto value = 0ull;
      auto bytes = 0;

      do {
         value |= (*ptr & 0x7f) << (bytes * 7ull);
         bytes++;
      } while (*(ptr++) & 0x80 && bytes <= 5);

      mPosition += bytes;
      return value;
   }

   std::string_view readStringView(size_t length)
   {
      assert(checkRemainingSpace(length));
      auto pos = mPosition;
      mPosition += length;
      return { reinterpret_cast<std::string_view::pointer>(mBuffer + pos), length };
   }

private:
   bool checkRemainingSpace(size_t bytes) const
   {
      return mPosition + bytes <= mSize;
   }

private:
   const char *mBuffer;
   size_t mSize;
   size_t mPosition;
};
