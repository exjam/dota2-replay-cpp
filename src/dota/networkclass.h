#pragma once
#include <map>
#include <cstddef>
#include "property.h"

namespace dota
{

struct NetworkClassBase;

struct NetworkProperty
{
   void *pointer;
   PropertyType type;
   const NetworkClassBase *dataTable = nullptr;
   std::size_t array_size;
};

struct NetworkClassBase
{
   std::string mClassName;
   std::string mTableName;
   std::map<std::string, NetworkProperty> mProperties;
};

struct NetworkClassList
{
   static NetworkClassList &Instance();

   static void add(NetworkClassBase *networkClass)
   {
      Instance().mNetworkClassMap[networkClass->mTableName] = networkClass;
   }

   static NetworkClassBase *get(const std::string &name)
   {
      return Instance().mNetworkClassMap[name];
   }

   std::map<std::string, NetworkClassBase*> mNetworkClassMap;
};

template<typename Type>
struct get_network_property_type
{
   static const auto value = std::is_class<Type>::value ? PropertyType::DataTable : PropertyType::Invalid;
   static const auto flags = PropertyFlag::None;
   static_assert(get_network_property_type<Type>::value != PropertyType::Invalid, "Invalid property type.");
};

template<>
struct get_network_property_type<int32_t>
{
   static const auto value = PropertyType::Int;
   static const auto flags = PropertyFlag::None;
};

template<>
struct get_network_property_type<int64_t>
{
   static const auto value = PropertyType::Int64;
   static const auto flags = PropertyFlag::None;
};

template<>
struct get_network_property_type<uint32_t>
{
   static const auto value = PropertyType::Int;
   static const auto flags = PropertyFlag::Unsigned;
};

template<>
struct get_network_property_type<uint64_t>
{
   static const auto value = PropertyType::Int64;
   static const auto flags = PropertyFlag::Unsigned;
};

template<>
struct get_network_property_type<float>
{
   static const auto value = PropertyType::Float;
   static const auto flags = PropertyFlag::None;
   static const auto array_size = 0;
};

template<typename Type>
struct NetworkClass {
   static const int value = 0;
};

#define DeclareNetworkClass(ClassName) \
   template<> \
   struct NetworkClass<ClassName> : public NetworkClassBase { \
      static NetworkClass<ClassName> value; \
      using NetworkedClass = ClassName; \
      NetworkClass(); \
   }; \

#define DeclareNetworkStruct(ClassName) \
   DeclareNetworkClass(ClassName)

#define BeginNetworkStruct(TableName) \
   BeginNetworkClass(TableName, TableName)

#define BeginNetworkClass(ClassName, TableName) \
   NetworkClass<ClassName> NetworkClass<ClassName>::value; \
   NetworkClass<ClassName>::NetworkClass() \
   { \
      mClassName = #ClassName; \
      mTableName = #TableName; \
      NetworkClassList::add(this);

#define NetworkProperty(ValueName) \
      { \
         using value_type = decltype(((NetworkedClass*)0)->ValueName); \
         auto &prop = mProperties[#ValueName]; \
         prop.pointer = reinterpret_cast<void*>(offsetof(NetworkedClass, ValueName)); \
         prop.type = get_network_property_type<std::remove_extent<value_type>::type>::value; \
         prop.array_size = std::extent<value_type>::value; \
         prop.dataTable = reinterpret_cast<const NetworkClassBase*>(&NetworkClass<std::remove_extent<value_type>::type>::value); \
      }

#define NetworkBaseClass(ClassName) \
      { \
         auto &prop = mProperties["baseclass"]; \
         prop.pointer = 0; \
         prop.type = PropertyType::DataTable; \
         prop.dataTable = &NetworkClass<ClassName>::value; \
      }

#define EndNetworkStruct() \
   }

#define EndNetworkClass() \
   }

}
