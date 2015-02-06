#pragma once
#include "arrayview.h"

// Wrapper around ArrayView with std::string like functions (if I bother to add them)
class StringView : public ArrayView<char>
{
public:
   StringView(const char *buffer, std::size_t size) :
      ArrayView(buffer, size)
   {
   }

   int compare(const char *other)
   {
      for (auto i = 0u; i < mSize; ++i) {
         if (mBuffer[i] != other[i]) {
            if (mBuffer[i] < other[i]) {
               return -1;
            } else {
               return 1;
            }
         }
      }

      return 0;
   }

private:
};
