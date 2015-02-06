#include <sstream>
#include <iostream>

#include "proto/netmessages.pb.h"

#include "entity/CDOTAPlayer.h"
#include "entity/CDOTA_PlayerResource.h"

#include "bitview.h"
#include "clientclass.h"
#include "demoparser.h"
#include "util.h"

namespace dota
{

Entity::~Entity()
{
   if (clientEntity && classInfo && classInfo->clientClass) {
      classInfo->clientClass->destroy(clientEntity);
      clientEntity = nullptr;
   }
}

EntityClass::~EntityClass()
{
   if (baseInstance && clientClass) {
      clientClass->destroy(baseInstance);
      baseInstance = nullptr;
   }
}

std::string EntityClass::getBaseClass() const
{
   if (sendTable) {
      for (auto &&prop : sendTable->properties) {
         if (prop.varName.compare("baseclass") == 0) {
            return prop.dtName;
         }
      }
   }

   return { };
}

bool DemoParser::parseEntityPropList(BitView &in, EntityPropList &props)
{
   auto offset = 0u;
   auto index = -1;

   while (true) {
      if (in.readBit()) {
         ++index;
      } else {
         offset = in.readVarUint32();

         if (offset == 0x3fff) {
            break;
         }

         index += offset + 1;
      }

      props.push_back(static_cast<std::size_t>(index));
   }

   return true;
}

void DemoParser::onEntityEnter(Entity &entity)
{
   mTickData.enterEntity.push_back(&entity);
}

void DemoParser::onEntityDelete(Entity &entity)
{
   mTickData.deleteEntity.push_back(std::make_pair(entity.id, entity.serial));

   auto id = entity.id;
   entity.~Entity();
   mEntities[id] = Entity { };
}

bool DemoParser::parseTempEntities(const CSVCMsg_TempEntities &msg)
{
   // TODO: Temp entities
   return false;
}

bool DemoParser::parsePacketEntities(const CSVCMsg_PacketEntities &msg)
{
   auto &entityData = msg.entity_data();
   auto in = BitView { entityData.data(), entityData.size() };
   auto classBits = getRequiredBits(mServerInfo.maxClasses);
   auto index = -1;
   auto propList = EntityPropList {};
   propList.reserve(128);

   for (int i = 0; i < msg.updated_entries(); ++i) {
      auto indexOffset = in.readUint32(6);
      auto indexExtra = (indexOffset >> 4) & 0x3;

      switch (indexExtra) {
      case 0x1:
         indexOffset = (indexOffset & 0x0f) | (in.readUint32(4) << 4);
         break;
      case 0x2:
         indexOffset = (indexOffset & 0x0f) | (in.readUint32(8) << 4);
         break;
      case 0x3:
         indexOffset = (indexOffset & 0x0f) | (in.readUint32(28) << 4);
         break;
      }

      index += indexOffset + 1;
      Entity &entity = mEntities[index];
      auto pvs = static_cast<EntityPVS>(in.readUint32(2));

      switch(pvs) {
      case EntityPVS::Preserve:
      {
         entity.pvs = EntityPVS::Preserve;
         assert(entity.classInfo);
         assert(entity.clientEntity);

         propList.clear();
         parseEntityPropList(in, propList);
         parseEntityProperties(in, *entity.classInfo, entity.clientEntity, propList);
         break;
      }
      break;
      case EntityPVS::Leave:
      {
         Entity &entity = mEntities[index];
         entity.pvs = EntityPVS::Leave;
         break;
      }
      case EntityPVS::Enter:
      {
         auto classId = in.readUint32(classBits);
         auto serial = in.readUint32(10);
         auto &entityClass = mClassList[classId];
         auto &entity = mEntities[index];

         if (entity.pvs != EntityPVS::Delete && entity.serial != serial) {
            onEntityDelete(entity);
         }

         entity.id = index;
         entity.serial = serial;
         entity.classInfo = &entityClass;
         entity.pvs = EntityPVS::Enter;

         if (entityClass.clientClass) {
            if (entityClass.baseInstance) {
               entity.clientEntity = entityClass.clientClass->create(entityClass.baseInstance);
            } else {
               entity.clientEntity = entityClass.clientClass->create();
            }
         } else {
            // TODO: Use slow entity with dynamic properties
            entity.clientEntity = nullptr;
         }

         propList.clear();
         parseEntityPropList(in, propList);
         parseEntityProperties(in, entityClass, entity.clientEntity, propList);
         onEntityEnter(entity);
         break;
      }
      case EntityPVS::Delete:
         Entity &entity = mEntities[index];
         entity.pvs = EntityPVS::Delete;
         onEntityDelete(entity);
         break;
      }
   }

   if (msg.is_delta()) {
      while (in.readBit()) {
         auto index = in.readUint32(11);
         Entity &entity = mEntities[index];
         entity.pvs = EntityPVS::Delete;
         onEntityDelete(entity);
      }
   }

   auto pos = in.getBufferPosition();
   auto len = entityData.size();
   assert(pos == len);
   return true;
}

}
