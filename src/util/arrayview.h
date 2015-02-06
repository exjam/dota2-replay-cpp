#pragma once
#include <cstddef>
#include <vector>

// None-owning view into a buffer, does not manage memory
template<typename Type>
class ArrayView
{
public:
   using ElementType = Type;

public:
   ArrayView(const Type *buffer, std::size_t size) :
      mBuffer(buffer),
      mSize(size)
   {
   }

   ArrayView(const std::vector<Type> &vec)
   {
      *this = vec;
   }

   template<std::size_t N>
   ArrayView(const Type buffer[N]) :
      mBuffer(buffer),
      mSize(N)
   {
   }

   ArrayView<Type> &operator=(const std::vector<Type> &vec)
   {
      mBuffer = vec.data();
      mSize = vec.size();
      return *this;
   }

   const Type *data() const
   {
      return mBuffer;
   }

   std::size_t size() const
   {
      return mSize;
   }

protected:
   const Type *mBuffer;
   std::size_t mSize;
};
