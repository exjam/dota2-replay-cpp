#include <iostream>
#include <snappy.h>
#include <sstream>

#include "proto/ai_activity.pb.h"
#include "proto/demo.pb.h"
#include "proto/dota_commonmessages.pb.h"
#include "proto/dota_modifiers.pb.h"
#include "proto/dota_usermessages.pb.h"
#include "proto/netmessages.pb.h"
#include "proto/network_connection.pb.h"
#include "proto/networkbasetypes.pb.h"
#include "proto/usermessages.pb.h"

#include "binarystream.h"
#include "bitstream.h"
#include "demoparser.h"

namespace dota
{

bool DemoParser::parseMessage(BinaryStream &in)
{
   auto kind = in.readVarint<int>();
   auto tick = in.readVarint<std::size_t>();
   auto size = in.readVarint<std::size_t>();
   auto data = std::vector<uint8_t> { };

   // Decompress with Snappy if needed
   if (kind & DEM_IsCompressed) {
      auto compressed = in.readBytes(size);

      if (!snappy::GetUncompressedLength(reinterpret_cast<const char*>(compressed.data()),
                                         compressed.size(),
                                         &size)) {
         return false;
      }

      data.resize(size);

      if (!snappy::RawUncompress(reinterpret_cast<const char*>(compressed.data()),
                                 compressed.size(),
                                 reinterpret_cast<char*>(data.data()))) {
         return false;
      }
   } else {
      data = in.readBytes(size);
   }

   // Trim any flags
   kind &= ~DEM_IsCompressed;

   switch (kind) {
   case DEM_ConsoleCmd:
      decodeMessage<CDemoConsoleCmd>(data, &DemoParser::handleDemoConsoleCmd);
      break;
   case DEM_FileHeader:
      decodeMessage<CDemoFileHeader>(data, &DemoParser::handleDemoFileHeader);
      break;
   case DEM_FileInfo:
      decodeMessage<CDemoFileInfo>(data, &DemoParser::handleDemoFileInfo);
      break;
   case DEM_SyncTick:
      decodeMessage<CDemoSyncTick>(data, &DemoParser::handleDemoSyncTick);
      break;
   case DEM_SendTables:
      decodeMessage<CDemoSendTables>(data, &DemoParser::handleDemoSendTables);
      break;
   case DEM_StringTables:
      decodeMessage<CDemoStringTables>(data, &DemoParser::handleDemoStringTables);
      break;
   case DEM_ClassInfo:
      decodeMessage<CDemoClassInfo>(data, &DemoParser::handleDemoClassInfo);
      break;
   case DEM_Packet:
   case DEM_SignonPacket:
      decodeMessage<CDemoPacket>(data, &DemoParser::handleDemoPacket);
      break;
   case DEM_FullPacket:
      decodeMessage<CDemoFullPacket>(data, &DemoParser::handleDemoFullPacket);
      break;
   case DEM_Error:
   case DEM_Stop:
   case DEM_CustomData:
   case DEM_CustomDataCallbacks:
   case DEM_UserCmd:
   case DEM_SaveGame:
   default:
      std::cout << "Unhandled message type " << kind << std::endl;
      return false;
   }

   return true;
}

bool DemoParser::parseSubMessage(BinaryStream &in)
{
   while (!in.eof()) {
      auto kind = in.readVarint<int>();
      auto size = in.readVarint<std::size_t>();
      auto data = in.readBytes(size);

      switch (kind) {
      case svc_SendTable:
         decodeMessage<CSVCMsg_SendTable>(data, &DemoParser::handleSendTable);
         break;
      case svc_ClassInfo:
         decodeMessage<CSVCMsg_ClassInfo>(data, &DemoParser::handleClassInfo);
         break;
      case svc_CreateStringTable:
         decodeMessage<CSVCMsg_CreateStringTable>(data, &DemoParser::handleCreateStringTable);
         break;
      case svc_UpdateStringTable:
         decodeMessage<CSVCMsg_UpdateStringTable>(data, &DemoParser::handleUpdateStringTable);
         break;
      case svc_UserMessage:
         decodeMessage<CSVCMsg_UserMessage>(data, &DemoParser::parseUserMessage);
         break;
      case svc_ServerInfo:
         decodeMessage<CSVCMsg_ServerInfo>(data, &DemoParser::handleServerInfo);
         break;
      case svc_PacketEntities:
         decodeMessage<CSVCMsg_PacketEntities>(data, &DemoParser::parsePacketEntities);
         break;
      case svc_GameEventList:
         decodeMessage<CSVCMsg_GameEventList>(data, &DemoParser::handleGameEventList);
         break;
      case svc_GameEvent:
         decodeMessage<CSVCMsg_GameEvent>(data, &DemoParser::handleGameEvent);
         break;
      case net_Tick:
         break;
      // networkbasetypes.pb.h
      case net_NOP:
      case net_Disconnect:
      case net_File:
      case net_SplitScreenUser:
      case net_StringCmd:
      case net_SetConVar:
      case net_SignonState:
      // netmessages.pb.h
      case svc_SetPause:
      case svc_VoiceInit:
      case svc_VoiceData:
      case svc_Print:
      case svc_Sounds:
      case svc_SetView:
      case svc_FixAngle:
      case svc_CrosshairAngle:
      case svc_BSPDecal:
      case svc_SplitScreen:
      case svc_EntityMessage:
      case svc_TempEntities:
      case svc_Prefetch:
      case svc_Menu:
      case svc_GetCvarValue:
      case svc_PacketReliable:
      case svc_FullFrameSplit:
      default:
         //std::cout << "Unhandled sub-message type " << kind << std::endl;
         return false;
      };
   }

   return true;
}

bool DemoParser::parseUserMessage(const CSVCMsg_UserMessage &message)
{
   auto kind = message.msg_type();
   auto data = message.msg_data();

   switch (kind) {
   case DOTA_UM_CourierKilledAlert:
      decodeMessage<CDOTAUserMsg_CourierKilledAlert>(data, &DemoParser::handleCourierKilledAlert);
      break;
   case DOTA_UM_AbilitySteal:
      decodeMessage<CDOTAUserMsg_AbilitySteal>(data, &DemoParser::handleAbilitySteal);
      break;
   // usermessages.pb.h
   case UM_AchievementEvent:
   case UM_CloseCaption:
   case UM_CloseCaptionDirect:
   case UM_CurrentTimescale:
   case UM_DesiredTimescale:
   case UM_Fade:
   case UM_GameTitle:
   case UM_Geiger:
   case UM_HintText:
   case UM_HudMsg:
   case UM_HudText:
   case UM_KeyHintText:
   case UM_MessageText:
   case UM_RequestState:
   case UM_ResetHUD:
   case UM_Rumble:
   case UM_SayText:
   case UM_SayText2:
   case UM_SayTextChannel:
   case UM_Shake:
   case UM_ShakeDir:
   case UM_StatsCrawlMsg:
   case UM_StatsSkipState:
   case UM_TextMsg:
   case UM_Tilt:
   case UM_Train:
   case UM_VGUIMenu:
   case UM_VoiceMask:
   case UM_VoiceSubtitle:
   case UM_SendAudio:
   case UM_CameraTransition:
   // dota_usermessages.pb.h
   case DOTA_UM_AbilityPing:
   case DOTA_UM_AddQuestLogEntry:
   case DOTA_UM_AddUnitToSelection:
   case DOTA_UM_AIDebugLine:
   case DOTA_UM_BoosterState:
   case DOTA_UM_BotChat:
   case DOTA_UM_BuyBackStateAlert:
   case DOTA_UM_CharacterSpeakConcept:
   case DOTA_UM_ChatEvent:
   case DOTA_UM_ChatWheel:
   case DOTA_UM_ClientLoadGridNav:
   case DOTA_UM_CoachHUDPing:
   case DOTA_UM_CombatHeroPositions:
   case DOTA_UM_CombatLogData:
   case DOTA_UM_CombatLogShowDeath:
   case DOTA_UM_CreateLinearProjectile:
   case DOTA_UM_CustomMsg:
   case DOTA_UM_DestroyLinearProjectile:
   case DOTA_UM_DodgeTrackingProjectiles:
   case DOTA_UM_EnemyItemAlert:
   case DOTA_UM_GamerulesStateChanged:
   case DOTA_UM_GlobalLightColor:
   case DOTA_UM_GlobalLightDirection:
   case DOTA_UM_HalloweenDrops:
   case DOTA_UM_HudError:
   case DOTA_UM_InvalidCommand:
   case DOTA_UM_ItemAlert:
   case DOTA_UM_ItemFound:
   case DOTA_UM_ItemPurchased:
   case DOTA_UM_LocationPing:
   case DOTA_UM_MapLine:
   case DOTA_UM_MiniKillCamInfo:
   case DOTA_UM_MinimapDebugPoint:
   case DOTA_UM_MinimapEvent:
   case DOTA_UM_MiniTaunt:
   case DOTA_UM_NevermoreRequiem:
   case DOTA_UM_OverheadEvent:
   case DOTA_UM_ParticleManager:
   case DOTA_UM_Ping:
   case DOTA_UM_PlayerMMR:
   case DOTA_UM_PredictionResult:
   case DOTA_UM_QuickBuyAlert:
   case DOTA_UM_ReceivedXmasGift:
   case DOTA_UM_SendFinalGold:
   case DOTA_UM_SendGenericToolTip:
   case DOTA_UM_SendRoshanPopup:
   case DOTA_UM_SendStatPopup:
   case DOTA_UM_SetNextAutobuyItem:
   case DOTA_UM_SharedCooldown:
   case DOTA_UM_ShowGenericPopup:
   case DOTA_UM_ShowSurvey:
   case DOTA_UM_SpectatorPlayerClick:
   case DOTA_UM_StatsHeroDetails:
   case DOTA_UM_StatsMatchDetails:
   case DOTA_UM_SwapVerify:
   case DOTA_UM_TournamentDrop:
   case DOTA_UM_TutorialFade:
   case DOTA_UM_TutorialFinish:
   case DOTA_UM_TutorialMinimapPosition:
   case DOTA_UM_TutorialPingMinimap:
   case DOTA_UM_TutorialRequestExp:
   case DOTA_UM_TutorialTipInfo:
   case DOTA_UM_UnitEvent:
   case DOTA_UM_UpdateSharedContent:
   case DOTA_UM_VoteEnd:
   case DOTA_UM_VoteStart:
   case DOTA_UM_VoteUpdate:
   case DOTA_UM_WillPurchaseAlert:
   case DOTA_UM_WorldLine:
   default:
      //std::cout << "Unhandled user-message type " << kind << std::endl;
      return false;
   }

   return true;
}

bool DemoParser::handleDemoClassInfo(const CDemoClassInfo &msg)
{
   for (int i = 0; i < msg.classes_size(); ++i) {
      auto &cls = msg.classes(i);
      auto info = ClassInfo { };
      info.id = cls.class_id();
      info.name = cls.network_name();
      info.tableName = cls.table_name();
      mClassInfo[info.id] = info;
   }

   return true;
}

bool DemoParser::handleClassInfo(const CSVCMsg_ClassInfo &msg)
{
   for (int i = 0; i < msg.classes_size(); ++i) {
      auto &cls = msg.classes(i);
      auto info = ClassInfo { };
      info.id = cls.class_id();
      info.name = cls.class_name();
      info.tableName = cls.data_table_name();
      mClassInfo[info.id] = info;
   }

   return true;
}

bool DemoParser::handleDemoFileInfo(const CDemoFileInfo &info)
{
   auto game = info.game_info();
   auto dota = game.dota();

   for (int i = 0; i < dota.player_info_size(); ++i) {
      auto player = dota.player_info(i);
      auto name = player.player_name();
      auto hero = player.hero_name();
      std::cout << "Player: " << name << " Hero: " << hero << std::endl;
   }

   return true;
}

bool DemoParser::handleDemoSyncTick(const CDemoSyncTick &/*msg*/)
{
   for (auto &&kvpair : mSendTables) {
      auto &table = kvpair.second;

      if (table.needsDecode) {
         flattenSendTable(table);
         table.needsDecode = false;
      }
   }

   return true;
}

bool DemoParser::handleDemoConsoleCmd(const CDemoConsoleCmd &cmd)
{
   auto str = cmd.cmdstring();
   std::cout << str << std::endl;
   return true;
}

bool DemoParser::handleDemoFileHeader(const CDemoFileHeader &header)
{
   return true;
}

bool DemoParser::handleSendTable(const CSVCMsg_SendTable &msg)
{
   auto name = msg.net_table_name();
   auto itr = mSendTables.find(name);

   if (itr != mSendTables.end()) {
      // Update?
      assert(0);
   } else {
      SendTable &table = mSendTables[name];
      table.name = name;
      table.needsDecode = msg.needs_decoder();
      table.properties.resize(msg.props_size());

      for (int i = 0; i < msg.props_size(); ++i) {
         auto &sp = table.properties[i];
         auto &prop = msg.props(i);

         sp.dtName = prop.dt_name();
         sp.varName = prop.var_name();
         sp.priority = prop.priority();
         sp.numBits = prop.num_bits();
         sp.numElements = prop.num_elements();
         sp.lowValue = prop.low_value();
         sp.highValue = prop.high_value();
         sp.type = static_cast<PropertyType>(prop.type());
         sp.flags = static_cast<PropertyFlag>(prop.flags());

         if (sp.isArray()) {
            assert(i > 0);
            sp.arrayElementType = &table.properties[i - 1];
         } else {
            sp.arrayElementType = nullptr;
         }
      }
   }

   return true;
}

bool DemoParser::handleStringTables(const CDemoStringTables &tables)
{
   for (auto i = 0; i < tables.tables_size(); ++i) {
      auto &table = tables.tables(i);
      auto name = table.table_name();

      assert(mStringTables.find(name) != mStringTables.end());
      auto &stringTable =  mStringTables[name];

      for (auto j = 0; j < table.items_size(); ++j) {
         auto &item = table.items(j);
         auto &entry = stringTable.entries[j];
         entry.strData = item.str();
         entry.userData = item.data();
      }
   }

   return true;
}

bool DemoParser::handleCreateStringTable(const CSVCMsg_CreateStringTable &msg)
{
   auto name = msg.name();
   assert(mStringTables.find(name) == mStringTables.end());

   auto &table = mStringTables[name];
   table.id = mStringTables.size() - 1;
   table.name = name;
   table.maxEntries = msg.max_entries();
   table.userDataFixedSize = msg.user_data_fixed_size();
   table.userDataSize = msg.user_data_size();
   table.userDataSizeBits = msg.user_data_size_bits();
   table.flags = msg.flags();
   table.entries.resize(table.maxEntries);

   auto length = msg.string_data().size();
   auto stream = std::istringstream { msg.string_data() };
   auto binary = BinaryStream { stream };
   auto in = BitStream { binary };
   auto result = parseStringTable(table, in, msg.num_entries());
   auto pos = binary.tell();
   assert(binary.eof());
   return result;
}

bool DemoParser::handleUpdateStringTable(const CSVCMsg_UpdateStringTable &msg)
{
   auto id = msg.table_id();
   auto itr = mStringTables.begin();

   while (itr != mStringTables.end()) {
      if (itr->second.id == id) {
         break;
      }

      ++itr;
   }

   assert(itr != mStringTables.end());

   auto length = msg.string_data().size();
   auto stream = std::istringstream { msg.string_data() };
   auto binary = BinaryStream { stream };
   auto in = BitStream { binary };
   auto result = parseStringTable(itr->second, in, msg.num_changed_entries());
   auto pos = binary.tell();
   assert(binary.eof());
   return result;
}

bool DemoParser::handleServerInfo(const CSVCMsg_ServerInfo &info)
{
   mServerInfo.maxClasses = info.max_classes();
   mServerInfo.tickInterval = info.tick_interval();
   mClassInfo.resize(mServerInfo.maxClasses);
   return true;
}

bool DemoParser::handleDemoPacket(const CDemoPacket &packet)
{
   auto stream = std::istringstream { packet.data() };
   auto in = BinaryStream { stream };
   return parseSubMessage(in);
}

bool DemoParser::handleDemoFullPacket(const CDemoFullPacket &packet)
{
   bool success = true;
   success &= handleDemoPacket(packet.packet());
   success &= handleStringTables(packet.string_table());
   return success;
}

bool DemoParser::handleDemoSendTables(const CDemoSendTables &sendTables)
{
   auto stream = std::istringstream { sendTables.data() };
   auto in = BinaryStream { stream };
   return parseSubMessage(in);
}

bool DemoParser::handleDemoStringTables(const CDemoStringTables &stringTables)
{
   for (auto i = 0; i < stringTables.tables_size(); ++i) {
      auto &table = stringTables.tables(i);
      auto name = table.table_name();
      auto itr = mStringTables.find(name);
      assert(itr != mStringTables.end());
      auto &stringTable = itr->second;

      for (auto j = 0; j < table.items_size(); ++j) {
         auto &item = table.items(j);
         auto &entry = stringTable.entries[j];

         // Erase from keymap incase key changes
         if (entry.strData.size() && entry.userData.size()) {
            auto prevItr = stringTable.keyMap.find(entry.strData);

            if (prevItr->second == &entry) {
               stringTable.keyMap.erase(prevItr);
            }
         }

         // Update entry
         entry.strData = item.str();
         entry.userData = item.data();

         // Add to keymap if needed
         if (entry.strData.size() && entry.userData.size()) {
            stringTable.keyMap[entry.strData] = &entry;
         }
      }
   }

   return true;
}

bool DemoParser::handleCourierKilledAlert(const CDOTAUserMsg_CourierKilledAlert &msg)
{
   auto entity = msg.entity_handle();
   auto value = msg.gold_value();
   auto team = msg.team();
   auto timestamp = msg.timestamp();
   return true;
}

bool DemoParser::handleAbilitySteal(const CDOTAUserMsg_AbilitySteal &msg)
{
   auto id = msg.ability_id();
   auto level = msg.ability_level();
   auto player = msg.player_id();
   return true;
}

}
