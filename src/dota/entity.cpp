#include <sstream>
#include <iostream>

#include "proto/netmessages.pb.h"

#include "entity/CDOTAPlayer.h"
#include "entity/CDOTA_PlayerResource.h"

#include "bitstream.h"
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

bool DemoParser::parseEntityPropList(BitStream &in, EntityPropList &props)
{
   auto offset = 0;
   auto index = -1;

   while (true) {
      if (in.readBit()) {
         ++index;
      } else {
         offset = in.readVarInt();

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
   if (mEventListeners.onEntityEnter) {
      mEventListeners.onEntityEnter(&entity);
   }
}

void DemoParser::onEntityPreserve(Entity &entity)
{
   if (mEventListeners.onEntityPreserve) {
      mEventListeners.onEntityPreserve(&entity);
   }
}

void DemoParser::onEntityLeave(Entity &entity)
{
   if (mEventListeners.onEntityLeave) {
      mEventListeners.onEntityLeave(&entity);
   }
}

void DemoParser::onEntityDelete(Entity &entity)
{
   if (mEventListeners.onEntityDelete) {
      mEventListeners.onEntityDelete(&entity);
   }

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
   auto stream = std::istringstream { msg.entity_data() };
   auto bin = BinaryStream { stream };
   auto in = BitStream { bin };
   auto classBits = getRequiredBits(mServerInfo.maxClasses);
   auto index = -1;

   for (int i = 0; i < msg.updated_entries(); ++i) {
      auto indexOffset = in.read<std::size_t>(6);
      auto indexExtra = (indexOffset >> 4) & 0x3;

      switch (indexExtra) {
      case 0x1:
         indexOffset = (indexOffset & 0x0f) | (in.read<std::size_t>(4) << 4);
         break;
      case 0x2:
         indexOffset = (indexOffset & 0x0f) | (in.read<std::size_t>(8) << 4);
         break;
      case 0x3:
         indexOffset = (indexOffset & 0x0f) | (in.read<std::size_t>(28) << 4);
         break;
      }

      index += indexOffset + 1;
      Entity &entity = mEntities[index];

      switch(static_cast<EntityPVS>(in.read<unsigned>(2))) {
      case EntityPVS::Preserve:
      {
         entity.pvs = EntityPVS::Preserve;
         assert(entity.classInfo);
         assert(entity.clientEntity);

         auto propList = EntityPropList {};
         parseEntityPropList(in, propList);
         parseEntityProperties(in, *entity.classInfo, entity.clientEntity, propList);
         onEntityPreserve(entity);
         break;
      }
      break;
      case EntityPVS::Leave:
      {
         Entity &entity = mEntities[index];
         entity.pvs = EntityPVS::Leave;
         onEntityLeave(entity);
         break;
      }
      case EntityPVS::Enter:
      {
         auto classId = in.read<std::size_t>(classBits);
         auto serial = in.read<unsigned>(10);
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

         auto propList = EntityPropList {};
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
         int index = in.read<std::size_t>(11);
         Entity &entity = mEntities[index];
         entity.pvs = EntityPVS::Delete;
         onEntityDelete(entity);
      }
   }

   auto pos = static_cast<std::size_t>(stream.tellg());
   auto len = msg.entity_data().size();
   assert(pos == len);
   return true;
}

}
