#pragma once
#include <map>
#include <string>
#include <vector>
#include <cassert>
#include "types.h"

template<std::size_t Size>
class fixed_string
{
public:
   fixed_string()
   {
      mData[0] = 0;
   }

   fixed_string &operator=(const std::string &other)
   {
      assert(other.size() < Size);
      strncpy_s(mData, Size, other.c_str(), other.size());
      return *this;
   }

   char *data()
   {
      return &mData[0];
   }

   std::string toStdString() const
   {
      return std::string(mData);
   }

   std::size_t size() const
   {
      return strlen(mData);
   }

   std::size_t bufferSize() const
   {
      return Size;
   }

   operator bool() const
   {
      return !!mData[0];
   }

private:
   char mData[Size];
};

class static_string
{
public:
   static_string() :
      mData(nullptr),
      mSize(0)
   {
   }

   static_string(const static_string &other) :
      mData(nullptr),
      mSize(0)
   {
      *this = other;
   }

   static_string(static_string &&other) :
      mData(nullptr),
      mSize(0)
   {
      *this = std::move(other);
   }

   ~static_string()
   {
      delete[] mData;
   }

   static_string &operator=(const std::string &other)
   {
      auto size = other.length();
      auto value = new char[size];
      memcpy(value, other.data(), size);
      set(value, size);
      return *this;
   }

   static_string &operator=(const static_string &other)
   {
      auto size = other.mSize;
      auto value = new char[size];
      memcpy(value, other.mData, size);
      set(value, size);
      return *this;
   }

   static_string &operator=(static_string &&other)
   {
      set(other.mData, other.mSize);
      other.mData = nullptr;
      other.mSize = 0;
      return *this;
   }

   void resize(std::size_t size)
   {
      set(new char[size], size);
   }

   void set(char *value, std::size_t size)
   {
      delete[] mData;
      mData = value;
      mSize = size;
   }

   char *data() const
   {
      return mData;
   }

   std::size_t size() const
   {
      return mSize;
   }

   std::string toStdString() const
   {
      return std::string(mData, mSize);
   }

   operator bool() const
   {
      return !!mData && !!mSize;
   }

private:
   char *mData;
   std::size_t mSize;
};

namespace dota
{

struct StringTable
{
   // Lets align Entry to 128 blocks
   static const std::size_t MAX_STRING_SIZE = 128 - sizeof(static_string);

   struct Entry
   {
      fixed_string<MAX_STRING_SIZE> strData;
      static_string userData;
   };

   std::size_t id;
   std::string name;
   std::size_t maxEntries;
   std::size_t userDataSize;
   std::size_t userDataSizeBits;
   bool userDataFixedSize;
   std::size_t flags;
   std::vector<Entry> entries;
   std::map<std::string, Entry*> keyMap;
   Tick lastUpdate;

   Entry *findEntry(std::string key)
   {
      auto itr = keyMap.find(key);

      if (itr != keyMap.end()) {
         return itr->second;
      } else {
         return nullptr;
      }
   }
};

}
