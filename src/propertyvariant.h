#pragma once
#include <cstdint>
#include <string>
#include <vector>
#include "property.h"

struct Vector2f
{
   float x, y;
};

struct Vector3f
{
   float x, y, z;
};

class PropertyVariant;
using PropertyInt = int32_t;
using PropertyInt64 = int64_t;
using PropertyFloat = float;
using PropertyVector = Vector3f;
using PropertyVectorXY = Vector2f;
using PropertyString = std::string;
using PropertyArray = std::vector<PropertyVariant>;

template<typename Type>
struct get_property_type
{
   static const auto value = PropertyType::Invalid;
   static_assert(get_property_type<Type>::value != PropertyType::Invalid, "Invalid property type.");
};

template<>
struct get_property_type<PropertyInt>
{
   static const auto value = PropertyType::Int;
};

template<>
struct get_property_type<PropertyInt64>
{
   static const auto value = PropertyType::Int64;
};

template<>
struct get_property_type<PropertyFloat>
{
   static const auto value = PropertyType::Float;
};

template<>
struct get_property_type<PropertyVector>
{
   static const auto value = PropertyType::Vector;
};

template<>
struct get_property_type<PropertyVectorXY>
{
   static const auto value = PropertyType::VectorXY;
};

template<>
struct get_property_type<PropertyString>
{
   static const auto value = PropertyType::String;
};

template<>
struct get_property_type<PropertyArray>
{
   static const auto value = PropertyType::Array;
};

class PropertyVariant
{
public:
   PropertyVariant() :
      mType(PropertyType::Invalid)
   {
   }

   PropertyVariant(const PropertyVariant &other)
   {
      *this = other;
   }

   PropertyVariant(PropertyVariant &&other)
   {
      *this = std::move(other);
   }

   ~PropertyVariant()
   {
      destroy();
   }

   const PropertyType type() const
   {
      return mType;
   }

   template<typename Type>
   Type &get()
   {
      assert(mType == get_property_type<Type>::value);
      return *reinterpret_cast<const Type*>(mBuffer.data());
   }

   template<typename Type>
   const Type &get() const
   {
      assert(mType == get_property_type<Type>::value);
      return *reinterpret_cast<const Type*>(mBuffer.data());
   }

   template<typename Type>
   void set(const Type &value)
   {
      changeType(get_property_type<Type>::value);
      *reinterpret_cast<Type*>(mBuffer.data()) = value;
   }

   template<typename Type>
   void set(Type &&value)
   {
      changeType(get_property_type<Type>::value);
      *reinterpret_cast<Type*>(mBuffer.data()) = std::move(value);
   }

   PropertyVariant &operator=(PropertyVariant &&other)
   {
      mType = other.mType;
      mBuffer = std::move(other.mBuffer);
      other.mType = PropertyType::Invalid;
      return *this;
   }

   PropertyVariant &operator=(const PropertyVariant &other)
   {
      changeType(other.type());

      switch (mType) {
      case PropertyType::Int:
         set(other.get<PropertyInt>());
         break;
      case PropertyType::Int64:
         set(other.get<PropertyInt64>());
         break;
      case PropertyType::Float:
         set(other.get<PropertyFloat>());
         break;
      case PropertyType::Vector:
         set(other.get<PropertyVector>());
         break;
      case PropertyType::VectorXY:
         set(other.get<PropertyVectorXY>());
         break;
      case PropertyType::String:
         set(other.get<PropertyString>());
         break;
      case PropertyType::Array:
         set(other.get<PropertyArray>());
         break;
      }

      return *this;
   }

private:
   void changeType(PropertyType newType)
   {
      if (mType == newType) {
         return;
      }

      destroy();
      mType = newType;

      switch (mType) {
      case PropertyType::Int:
         mBuffer.resize(sizeof(PropertyInt));
         break;
      case PropertyType::Int64:
         mBuffer.resize(sizeof(PropertyInt64));
         break;
      case PropertyType::Float:
         mBuffer.resize(sizeof(PropertyFloat));
         break;
      case PropertyType::Vector:
         mBuffer.resize(sizeof(PropertyVector));
         new (mBuffer.data()) PropertyVector();
         break;
      case PropertyType::VectorXY:
         mBuffer.resize(sizeof(PropertyVectorXY));
         new (mBuffer.data()) PropertyVectorXY();
         break;
      case PropertyType::String:
         mBuffer.resize(sizeof(PropertyString));
         new (mBuffer.data()) PropertyString();
         break;
      case PropertyType::Array:
         mBuffer.resize(sizeof(PropertyArray));
         new (mBuffer.data()) PropertyArray();
         break;
      }
   }

   void destroy()
   {
      switch (mType) {
      case PropertyType::Vector:
         reinterpret_cast<PropertyVector*>(mBuffer.data())->~PropertyVector();
         break;
      case PropertyType::VectorXY:
         reinterpret_cast<PropertyVectorXY*>(mBuffer.data())->~PropertyVectorXY();
         break;
      case PropertyType::String:
         reinterpret_cast<PropertyString*>(mBuffer.data())->~PropertyString();
         break;
      case PropertyType::Array:
         reinterpret_cast<PropertyArray*>(mBuffer.data())->~PropertyArray();
         break;
      }

      mType = PropertyType::Invalid;
   }

   PropertyType mType;
   std::vector<uint8_t> mBuffer;
};

std::ostream& operator<<(std::ostream& os, const PropertyVariant& var);
