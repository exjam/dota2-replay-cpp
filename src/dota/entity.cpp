#include <sstream>
#include <iostream>

#include "proto/netmessages.pb.h"

#include "bitstream.h"
#include "demoparser.h"
#include "util.h"

namespace dota
{

using EntityPropList = std::vector<std::size_t>;

static EntityPropList parseEntityPropList(BitStream &in)
{
   auto propList = EntityPropList { };
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

      propList.push_back(static_cast<std::size_t>(index));
   }

   return propList;
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

      switch(in.read<unsigned>(2)) {
      case EntityPVS::Preserve:
      {
         //std::cout << "Preserve Entity " << index << std::endl;
         Entity &entity = mEntities[index];
         entity.pvs = EntityPVS::Preserve;
         assert(entity.classInfo);

         auto &recvTable = mReceiveTables[entity.classInfo->tableName];
         auto entityPropList = parseEntityPropList(in);

         //std::cout << "Entity Properties" << std::endl;
         for (auto &&propID : entityPropList) {
            auto &prop = recvTable.properties[propID];
            auto &value = entity.state.properties[propID];
            parsePropertyVariant(in, *prop.sendProp, value);
            //std::cout << prop.varName << " = " << value << std::endl;
         }
         break;
      }
      break;
      case EntityPVS::Leave:
      {
         //std::cout << "Leave Entity " << index << std::endl;
         Entity &entity = mEntities[index];
         entity.pvs = EntityPVS::Leave;
         break;
      }
      case EntityPVS::Enter:
      {
         //std::cout << "Enter Entity " << index << std::endl;

         auto classId = in.read<std::size_t>(classBits);
         auto classIdStr = std::to_string(classId);
         auto serial = in.read<unsigned>(10);
         auto &classInfo = mClassInfo[classId];
         auto &recvTable = mReceiveTables[classInfo.tableName];
         auto &baselineTable = mStringTables["instancebaseline"];
         auto &entity = mEntities[index];

         if (entity.serial != serial) {
            entity = Entity { };
         }

         entity.serial = serial;
         entity.classInfo = &classInfo;
         entity.pvs = EntityPVS::Enter;
         entity.state.properties.resize(recvTable.properties.size());


         auto baselineItr = baselineTable.keyMap.find(classIdStr);
         if (baselineItr != baselineTable.keyMap.end()) {
            auto baseline = baselineItr->second;
            auto baselineStream = std::istringstream { baseline->userData };
            auto baselineBinary = BinaryStream { baselineStream };
            auto baselineIn = BitStream { baselineBinary };

            //std::cout << "Baseline Properties" << std::endl;
            auto baselinePropList = parseEntityPropList(baselineIn);

            for (auto &&propID : baselinePropList) {
               auto &prop = recvTable.properties[propID];
               auto &value = entity.state.properties[propID];
               parsePropertyVariant(baselineIn, *prop.sendProp, value);
               //std::cout << (baselineIn.mOffset - 8 + 8 * (unsigned)baselineStream.tellg()) << " " << prop.varName << " = " << value << std::endl;
            }
         } else {
            std::cout << "Warning: no baseline properties found for " << classInfo.tableName << std::endl;
         }

         //std::cout << "Entity Properties" << std::endl;
         auto entityPropList = parseEntityPropList(in);

         for (auto &&propID : entityPropList) {
            auto &prop = recvTable.properties[propID];
            auto &value = entity.state.properties[propID];
            parsePropertyVariant(in, *prop.sendProp, value);
            //std::cout << (baselineIn.mOffset - 8 + 8 * (unsigned)stream.tellg()) << " " << prop.varName << " = " << value << std::endl;
         }
         break;
      }
      case EntityPVS::Delete:
         //std::cout << "Delete Entity " << index << std::endl;
         mEntities[index] = { };
         mEntities[index].pvs = EntityPVS::Delete;
         break;
      }
   }

   return true;
}

}
