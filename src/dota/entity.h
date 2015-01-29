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
   ClientClassID clientClassID;
   SendTable *sendTable = nullptr;
   ClientEntity *baseInstance = nullptr;
   const ClientClassBase *clientClass = nullptr;
   std::vector<ReceiveProperty> properties;
   std::map<std::string, ReceiveProperty*> propertyMap;

};

using EntityID = uint32_t;
using EntitySerial = uint32_t;
using EntityHandle = std::pair<EntityID, EntitySerial>;

struct Entity
{
   ~Entity();

   EntityID id = 0;
   EntitySerial serial = 0;
   EntityPVS pvs = EntityPVS::Delete;
   EntityClass *classInfo = nullptr;
   ClientEntity *clientEntity = nullptr;
};

}
