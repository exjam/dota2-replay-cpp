#pragma once
#include <cstdint>
#include <map>
#include <vector>
#include "clientclass.h"

namespace dota
{

struct SendTable;
struct Property;

enum class EntityPVS
{
   Preserve,
   Leave,
   Enter,
   Delete
};

struct ReceiveProperty
{
   std::string varName;
   std::ptrdiff_t offset = -1;
   const SendTable *table = nullptr;
   const Property *sendProp = nullptr;
   const ClientProperty *clientProp = nullptr;
};

struct EntityClass
{
   ~EntityClass();
   std::string getBaseClass() const;

   std::size_t id;
   std::string name;
   std::string tableName;
   SendTable *sendTable = nullptr;
   ClientEntity *baseInstance = nullptr;
   std::vector<ReceiveProperty> properties;
   std::map<std::string, ReceiveProperty*> propertyMap;
   ClientClassID clientClassID;
   const ClientClassBase *clientClass = nullptr;
};

using EntityID = uint32_t;
using EntitySerial = uint32_t;

struct EntityHandle
{
   EntityID id = 0;
   EntitySerial serial = 0;

   bool operator==(const EntityHandle &other) const
   {
      return (id == other.id && serial == other.serial);
   }
};

struct Entity
{
   ~Entity();

   EntityHandle handle;
   EntityPVS pvs = EntityPVS::Delete;
   EntityClass *classInfo = nullptr;
   ClientEntity *clientEntity = nullptr;
};

template<typename ClassType>
bool is_a(const Entity *entity)
{
   assert(entity && entity->classInfo);
   return entity->classInfo->clientClassID == dota::ClientClass<ClassType>::ClassID;
}

template<typename ClassType>
class entity_ptr
{
public:
   entity_ptr() :
      mEntity(nullptr)
   {
   }

   entity_ptr(const dota::Entity *entity)
   {
      *this = entity;
   }

   entity_ptr &operator=(const dota::Entity *entity)
   {
      assert(entity && entity->classInfo);
      assert(is_a<ClassType>(entity));
      mEntity = entity;
      return *this;
   }

   operator bool() const
   {
      return mEntity != nullptr;
   }

   bool operator==(const dota::EntityHandle &handle) const
   {
      return mEntity->handle == handle;
   }

   const ClassType *operator->() const
   {
      return reinterpret_cast<ClassType*>(mEntity->clientEntity);
   }

private:
   const dota::Entity *mEntity;
};

template<typename ClassType>
entity_ptr<ClassType> make_entity_ptr(const Entity *entity)
{
   return { entity };
}

}
