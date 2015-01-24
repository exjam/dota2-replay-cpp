#pragma once
#include <map>
#include <cstddef>
#include "property.h"
#include "vector3f.h"
#include "vector2f.h"

namespace dota
{

struct ClientClassBase;
using ClientClassID = std::size_t;

// ClientEntity must be destroyed through ClientClassBase->destroy(entity)
struct ClientEntity {
   ClientEntity() = delete;
   ClientEntity(const ClientEntity&) = delete;
   ClientEntity& operator=(const ClientEntity&) = delete;
   ~ClientEntity() = delete;
};

// A property within a client class
struct ClientProperty
{
   std::ptrdiff_t offset;
   PropertyType type;
   std::size_t arraySize; // Only defined for fixed array type[N]
   const ClientClassBase *dataTable; // Only defined for struct types
   struct ElementGetter *elemGetter; // Only defined for std::vector/array[N] types
};

// Reflection for our C++ client classes!
struct ClientClassBase
{
   virtual ClientEntity *create() const = 0;
   virtual ClientEntity *create(const ClientEntity *copy) const = 0;
   virtual void destroy(ClientEntity *entity) const = 0;
   virtual ClientClassID classID() const = 0;
   virtual std::size_t getSize() const = 0;

   const ClientProperty *findProperty(const std::string &name) const
   {
      auto itr = properties.find(name);

      if (itr != properties.end()) {
         return &itr->second;
      } else if (baseClass) {
         return baseClass->findProperty(name);
      } else {
         return nullptr;
      }
   }

   std::string className;
   std::string tableName;
   const ClientClassBase *baseClass;
   std::map<std::string, ClientProperty> properties;
};

// List of all reflected client classes
struct ClientClassList
{
   static ClientClassID GetUniqueID();

   static const ClientClassBase *get(const std::string &name)
   {
      auto itr = mClassMap.find(name);

      if (itr != mClassMap.end()) {
         return itr->second;
      } else {
         return nullptr;
      }
   }

   static std::map<std::string, const ClientClassBase*> mClassMap;
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
};

template<>
struct get_network_property_type<Vector3f>
{
   static const auto value = PropertyType::Vector;
   static const auto flags = PropertyFlag::None;
};

template<>
struct get_network_property_type<Vector2f>
{
   static const auto value = PropertyType::VectorXY;
   static const auto flags = PropertyFlag::None;
};

template<>
struct get_network_property_type<std::string>
{
   static const auto value = PropertyType::String;
   static const auto flags = PropertyFlag::None;
};

template<typename Type, std::size_t N>
struct get_network_property_type<Type[N]>
{
   static const auto value = get_network_property_type<Type>::value;
   static const auto flags = get_network_property_type<Type>::flags;
};

template<typename Type>
struct get_network_property_type<std::vector<Type>>
{
   static const auto value = get_network_property_type<Type>::value;
   static const auto flags = get_network_property_type<Type>::flags;
};

template<typename Type>
struct ClientClass
{
};

// All allowed value types for client properties
template<>
struct ClientClass<int32_t>
{
   static const auto InstancePtr = 0;
};

template<>
struct ClientClass<uint32_t>
{
   static const auto InstancePtr = 0;
};

template<>
struct ClientClass<float>
{
   static const auto InstancePtr = 0;
};

template<>
struct ClientClass<Vector3f>
{
   static const auto InstancePtr = 0;
};

template<>
struct ClientClass<Vector2f>
{
   static const auto InstancePtr = 0;
};

template<>
struct ClientClass<std::string>
{
   static const auto InstancePtr = 0;
};

template<>
struct ClientClass<int64_t>
{
   static const auto InstancePtr = 0;
};

template<>
struct ClientClass<uint64_t>
{
   static const auto InstancePtr = 0;
};

template<typename Type>
struct ClientClass<std::vector<Type>>
{
   static const auto InstancePtr = 0;
};

template<typename Type, std::size_t N>
struct ClientClass<Type[N]>
{
   static const auto InstancePtr = 0;
};

// Useful for getting elements from a dynamic runtime i dunno wtf is array type
struct ElementGetter
{
   virtual std::ptrdiff_t getElementPtr(std::ptrdiff_t container, std::size_t elem) const = 0;
};

template<typename Type>
struct ContainerElementGetter : public ElementGetter
{
};

template<typename Type, std::size_t N>
struct ContainerElementGetter<Type[N]> : public ElementGetter
{
   std::ptrdiff_t getElementPtr(std::ptrdiff_t container, std::size_t elem) const
   {
      Type *arr = reinterpret_cast<Type*>(container);
      assert(elem < N);
      return reinterpret_cast<std::ptrdiff_t>(arr + elem);
   }
};

template<typename Type>
struct ContainerElementGetter<std::vector<Type>> : public ElementGetter
{
   std::ptrdiff_t getElementPtr(std::ptrdiff_t container, std::size_t elem) const
   {
      std::vector<Type> &vec = *reinterpret_cast<std::vector<Type>*>(container);

      // Only allow elem to push_back 1
      if (vec.size() == elem) {
         vec.resize(elem + 1);
      }
      assert(elem < vec.size());
      return reinterpret_cast<std::ptrdiff_t>(&vec[elem]);
   }
};

// Get an element getter for any type
template<typename Type>
struct get_element_getter
{
   static ElementGetter *get()
   {
      return nullptr;
   }
};

template<typename Type, std::size_t N>
struct get_element_getter<Type[N]>
{
   static ElementGetter *get()
   {
      return new ContainerElementGetter<Type[N]>();
   }
};

template<typename Type>
struct get_element_getter<std::vector<Type>>
{
   static ElementGetter *get()
   {
      return new ContainerElementGetter<std::vector<Type>>();
   }
};

#define DeclareClientClass(ClassName) \
   template<> \
   struct ClientClass<ClassName> : public ClientClassBase { \
      static ClientClass<ClassName> Instance; \
      static const ClientClassBase *InstancePtr; \
      static ClientClassID ClassID; \
      using WrappedClass = ClassName; \
      ClientClass(); \
      virtual ClientEntity *create() const override; \
      virtual ClientEntity *create(const ClientEntity *copy) const override; \
      virtual void destroy(ClientEntity *entity) const override; \
      virtual ClientClassID classID() const override; \
      virtual std::size_t getSize() const override; \
   };

#define BeginClientClass(ClassName, TableName) \
   ClientClass<ClassName> ClientClass<ClassName>::Instance; \
   const ClientClassBase *ClientClass<ClassName>::InstancePtr = reinterpret_cast<ClientClassBase*>(&ClientClass<ClassName>::Instance); \
   ClientClassID ClientClass<ClassName>::ClassID = ClientClassList::GetUniqueID(); \
   ClientEntity *ClientClass<ClassName>::create() const { \
      return reinterpret_cast<ClientEntity*>(new ClassName());\
   } \
   ClientEntity *ClientClass<ClassName>::create(const ClientEntity *copy) const { \
      return reinterpret_cast<ClientEntity*>(new ClassName(*reinterpret_cast<const ClassName*>(copy)));\
   } \
   void ClientClass<ClassName>::destroy(ClientEntity *entity) const { \
      delete reinterpret_cast<ClassName*>(entity); \
   } \
   ClientClassID ClientClass<ClassName>::classID() const { \
      return ClientClass<ClassName>::ClassID; \
   } \
   std::size_t ClientClass<ClassName>::getSize() const { \
      return sizeof(ClassName); \
   } \
   ClientClass<ClassName>::ClientClass() \
   { \
      className = #ClassName; \
      tableName = #TableName;

#define AddClientProperty(ValueName) \
      { \
         using value_type = decltype(((WrappedClass*)0)->ValueName); \
         auto &prop = properties[#ValueName]; \
         prop.offset = offsetof(WrappedClass, ValueName); \
         prop.type = get_network_property_type<std::remove_extent<value_type>::type>::value; \
         prop.arraySize = std::extent<value_type>::value; \
         prop.dataTable = ClientClass<std::remove_extent<value_type>::type>::InstancePtr; \
         prop.elemGetter = get_element_getter<value_type>::get();\
      }

#define ClientBaseClass(ClassName) \
      { \
         baseClass = ClientClass<ClassName>::InstancePtr; \
      }

#define EndClientClass() \
   }

// "Structs" are the same than classes, but do not have class names, only table names
#define DeclareClientStruct(TableName) \
   DeclareClientClass(TableName)

#define BeginClientStruct(TableName) \
   BeginClientClass(TableName, TableName)

#define EndClientStruct() \
   EndClientClass()

}
