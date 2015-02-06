#pragma once
#include <cassert>
#include <cstdint>
#include <string>
#include <vector>
#include "arrayview.h"
#include "stringview.h"

// TODO: Rename BufferView?
class BinaryStream
{
public:
   BinaryStream(const char *buffer, std::size_t size) :
      mBuffer(buffer),
      mSize(size),
      mPosition(0)
   {
   }

   BinaryStream(const std::string &str) :
      mBuffer(str.c_str()),
      mSize(str.size()),
      mPosition(0)
   {
   }

   void seek(std::size_t pos)
   {
      mPosition = pos;
   }

   void skip(std::size_t bytes)
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

   std::size_t readVarInt()
   {
      auto ptr = reinterpret_cast<const uint8_t*>(mBuffer + mPosition);
      auto value = std::size_t { 0 };
      auto bytes = 0u;

      do {
         value |= (*ptr & 0x7f) << (bytes * 7);
         bytes++;
      } while (*(ptr++) & 0x80);

      mPosition += bytes;
      return value;
   }

   template<typename Type>
   ArrayView<Type> readArrayView(std::size_t length)
   {
      assert(checkRemainingSpace(length));
      auto pos = mPosition;
      mPosition += length;
      return { reinterpret_cast<const Type*>(mBuffer + pos), length };
   }

   StringView readStringView(std::size_t length)
   {
      assert(checkRemainingSpace(length));
      auto pos = mPosition;
      mPosition += length;
      return { reinterpret_cast<const StringView::ElementType*>(mBuffer + pos), length };
   }

private:
   bool checkRemainingSpace(std::size_t bytes) const
   {
      return mPosition + bytes <= mSize;
   }

private:
   const char *mBuffer;
   std::size_t mSize;
   std::size_t mPosition;
};
