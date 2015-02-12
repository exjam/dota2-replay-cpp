#include <iostream>
#include <snappy.h>
#include <sstream>

#include "proto/ai_activity.pbsl.h"
#include "proto/demo.pbsl.h"
#include "proto/dota_commonmessages.pbsl.h"
#include "proto/dota_modifiers.pbsl.h"
#include "proto/dota_usermessages.pbsl.h"
#include "proto/netmessages.pbsl.h"
#include "proto/network_connection.pbsl.h"
#include "proto/networkbasetypes.pbsl.h"
#include "proto/usermessages.pbsl.h"

#include "byteview.h"
#include "bitview.h"
#include "clientclass.h"
#include "demoparser.h"
#include "util.h"

namespace dota
{

auto decomp = std::vector<char> { };

bool DemoParser::parseMessage(ByteView &in)
{
   auto kind = in.readVarint32();
   auto comp = !!(kind & DEM_IsCompressed);
   auto tick = in.readVarint32();
   auto size = static_cast<size_t>(in.readVarint32());

   // Update tick?
   if (tick != mTick && kind != DEM_FileInfo) {
      onTick(tick);
      mTick = tick;
   }

   // Trim flags
   kind &= ~DEM_IsCompressed;

   // Skip filtered messages
   if (mParseProfile) {
      if (!mParseProfile->msg[kind]) {
         in.skip(size);
         return true;
      }
   }

   // Read data and decompress with Snappy if needed
   auto data = in.readStringView(size);

   if (comp) {
      if (!snappy::GetUncompressedLength(data.data(), data.size(), &size)) {
         return false;
      }

      decomp.resize(size);

      if (!snappy::RawUncompress(data.data(), data.size(), decomp.data())) {
         return false;
      }

      // Update our string_view to point to decompressed data
      data = std::string_view { decomp.data(), decomp.size() };
   }

   switch (kind) {
   case DEM_ClassInfo:
      decodeMessage<CDemoClassInfo>(data, &DemoParser::handleDemoClassInfo);
      break;
   case DEM_ConsoleCmd:
      decodeMessage<CDemoConsoleCmd>(data, &DemoParser::handleDemoConsoleCmd);
      break;
   case DEM_FileHeader:
      decodeMessage<CDemoFileHeader>(data, &DemoParser::handleDemoFileHeader);
      break;
   case DEM_FileInfo:
      decodeMessage<CDemoFileInfo>(data, &DemoParser::handleDemoFileInfo);
      break;
   case DEM_FullPacket:
      decodeMessage<CDemoFullPacket>(data, &DemoParser::handleDemoFullPacket);
      break;
   case DEM_SendTables:
      decodeMessage<CDemoSendTables>(data, &DemoParser::handleDemoSendTables);
      break;
   case DEM_SyncTick:
      decodeMessage<CDemoSyncTick>(data, &DemoParser::handleDemoSyncTick);
      break;
   case DEM_StringTables:
      decodeMessage<CDemoStringTables>(data, &DemoParser::handleDemoStringTables);
      break;
   case DEM_Packet:
   case DEM_SignonPacket:
      decodeMessage<CDemoPacket>(data, &DemoParser::handleDemoPacket);
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

bool DemoParser::parseSubMessage(ByteView &in)
{
   while (!in.eof()) {
      auto kind = in.readVarint32();
      auto size = in.readVarint32();

      // Skip filtered submessages
      if (mParseProfile && !mParseProfile->sub[kind]) {
         in.skip(size);
         continue;
      }

      auto data = in.readStringView(size);

      switch (kind) {
      case net_SetConVar:
         decodeMessage<CNETMsg_SetConVar>(data, &DemoParser::handleSetConVar);
         break;
      case net_SignonState:
         decodeMessage<CNETMsg_SignonState>(data, &DemoParser::handleSignonState);
         break;
      case net_StringCmd:
         decodeMessage<CNETMsg_StringCmd>(data, &DemoParser::handleStringCmd);
         break;
      case net_Tick:
         decodeMessage<CNETMsg_Tick>(data, &DemoParser::handleTick);
         break;
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
      case svc_TempEntities:
         decodeMessage<CSVCMsg_TempEntities>(data, &DemoParser::parseTempEntities);
         break;
      // networkbasetypes.pb.h
      case net_NOP:
      case net_Disconnect:
      case net_File:
      case net_SplitScreenUser:
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
      case svc_Prefetch:
      case svc_Menu:
      case svc_GetCvarValue:
      case svc_PacketReliable:
      case svc_FullFrameSplit:
      default:
         std::cout << "Unhandled sub-message type " << kind << std::endl;
         break;
      };
   }

   return true;
}

bool DemoParser::addEntityClass(std::size_t id, std::string name, std::string tableName)
{
   assert(id < mClassList.size());
   auto &entityClass = mClassList[id];
   entityClass.id = id;
   entityClass.name = std::move(name);
   entityClass.tableName = std::move(tableName);
   entityClass.sendTable = findSendTableByName(entityClass.tableName);
   entityClass.clientClass = ClientClassList::get(entityClass.tableName);
   entityClass.clientClassID = entityClass.clientClass ? entityClass.clientClass->classID() : 0;
   mClassTableMap[entityClass.tableName] = &entityClass;
   return true;
}

bool DemoParser::handleDemoClassInfo(const CDemoClassInfo &msg)
{
   for (auto i = 0u; i < msg.classes.size(); ++i) {
      auto &cls = msg.classes[i];
      addEntityClass(cls.class_id, cls.network_name.to_string(), cls.table_name.to_string());
   }

   return true;
}

bool DemoParser::handleClassInfo(const CSVCMsg_ClassInfo &msg)
{
   for (auto i = 0u; i < msg.classes.size(); ++i) {
      auto &cls = msg.classes[i];
      addEntityClass(cls.class_id, cls.class_name.to_string(), cls.data_table_name.to_string());
   }

   return true;
}

bool DemoParser::handleDemoFileInfo(const CDemoFileInfo &info)
{
   auto &game = info.game_info;
   auto &dota = game.dota;

   mGameInfo.ticks = info.playback_ticks;
   mGameInfo.seconds = info.playback_time;
   mGameInfo.frames = info.playback_frames;

   mGameInfo.matchID = dota.match_id;
   mGameInfo.gameMode = dota.game_mode;
   mGameInfo.gameWinner = static_cast<TeamID>(dota.game_winner);
   mGameInfo.leagueID = dota.leagueid;
   mGameInfo.endTime = dota.end_time;
   mGameInfo.dire.id = dota.dire_team_id;
   mGameInfo.dire.tag = dota.dire_team_tag.to_string();
   mGameInfo.radiant.id = dota.radiant_team_id;
   mGameInfo.radiant.tag = dota.radiant_team_tag.to_string();

   mGameInfo.players.clear();
   mGameInfo.pickBans.clear();

   for (auto i = 0u; i < dota.player_info.size(); ++i) {
      auto &player = dota.player_info[i];
      auto playerInfo = GameInfo::Player { };
      playerInfo.hero = player.hero_name.to_string();
      playerInfo.name = player.player_name.to_string();
      playerInfo.isFakeClient = player.is_fake_client;
      playerInfo.steamID = player.steamid;
      playerInfo.team = static_cast<TeamID>(player.game_team);
      mGameInfo.players.push_back(playerInfo);
   }

   for (auto i = 0u; i < dota.picks_bans.size(); ++i) {
      auto &pickBan = dota.picks_bans[i];
      auto pickBanInfo = GameInfo::PickBan { };
      pickBanInfo.hero = pickBan.hero_id;
      pickBanInfo.team = static_cast<TeamID>(pickBan.team);
      pickBanInfo.type = static_cast<GameInfo::PickBanType>(pickBan.is_pick);
      mGameInfo.pickBans.push_back(pickBanInfo);
   }

   return true;
}

bool DemoParser::handleDemoSyncTick(const CDemoSyncTick &msg)
{
   // TODO: handleDemoSyncTick
   return true;
}

bool DemoParser::handleDemoConsoleCmd(const CDemoConsoleCmd &cmd)
{
   // TODO: handleDemoConsoleCmd
   return true;
}

bool DemoParser::handleStringCmd(const CNETMsg_StringCmd &msg)
{
   // TODO: handleStringCmd
   return true;
}

bool DemoParser::handleDemoFileHeader(const CDemoFileHeader &header)
{
   mFileHeader.demoFileStamp = header.demo_file_stamp.to_string();
   mFileHeader.networkProtocol = header.network_protocol;
   mFileHeader.serverName = header.server_name.to_string();
   mFileHeader.clientName = header.client_name.to_string();
   mFileHeader.mapName = header.map_name.to_string();
   mFileHeader.gameDirectory = header.game_directory.to_string();
   mFileHeader.fullpacketsVersion = header.fullpackets_version;
   mFileHeader.allowClientsideEntities = header.allow_clientside_entities;
   mFileHeader.allowClientsideParticles = header.allow_clientside_particles;
   return true;
}

bool DemoParser::handleSetConVar(const CNETMsg_SetConVar &msg)
{
   auto &convars = msg.convars;

   for (auto i = 0u; i < convars.cvars.size(); ++i) {
      auto &cvar = convars.cvars[i];
      mConsoleVars[cvar.name.to_string()] = cvar.value.to_string();
   }

   return true;
}

bool DemoParser::handleTick(const CNETMsg_Tick &msg)
{
   // TODO: handleTick
   return true;
}

bool DemoParser::handleSignonState(const CNETMsg_SignonState &msg)
{
   mSignonState.mapName = msg.map_name.to_string();
   mSignonState.numServerPlayers = msg.num_server_players;
   mSignonState.spawnCount = msg.spawn_count;
   mSignonState.state = static_cast<SignonState>(msg.signon_state);
   mSignonState.playerNetworkIDs.clear();

   for (auto i = 0u; i < msg.players_networkids.size(); ++i) {
      mSignonState.playerNetworkIDs.push_back(msg.players_networkids[i].to_string());
   }

   return true;
}

bool DemoParser::handleSendTable(const CSVCMsg_SendTable &msg)
{
   auto name = msg.net_table_name.to_string();
   assert(!findSendTableByName(name));

   SendTable &table = mSendTables[name];
   table.name = std::move(name);
   table.needsDecode = msg.needs_decoder;
   table.properties.resize(msg.props.size());

   for (auto i = 0u; i < msg.props.size(); ++i) {
      auto &sp = table.properties[i];
      auto &prop = msg.props[i];

      sp.dtName = prop.dt_name.to_string();
      sp.varName = prop.var_name.to_string();
      sp.priority = prop.priority;
      sp.numBits = prop.num_bits;
      sp.numElements = prop.num_elements;
      sp.lowValue = prop.low_value;
      sp.highValue = prop.high_value;
      sp.type = static_cast<PropertyType>(prop.type);
      sp.flags = static_cast<PropertyFlag>(prop.flags);

      if (sp.isArray()) {
         assert(i > 0);
         sp.arrayElementType = &table.properties[i - 1];
      } else {
         sp.arrayElementType = nullptr;
      }
   }

   return true;
}

bool DemoParser::handleCreateStringTable(const CSVCMsg_CreateStringTable &msg)
{
   auto name = msg.name.to_string();
   assert(!findStringTableByName(name));

   auto &table = mStringTables[name];
   table.id = mStringTables.size() - 1;
   table.name = std::move(name);
   table.maxEntries = msg.max_entries;
   table.userDataFixedSize = msg.user_data_fixed_size;
   table.userDataSize = msg.user_data_size;
   table.userDataSizeBits = msg.user_data_size_bits;
   table.flags = msg.flags;
   table.entries.resize(table.maxEntries);

   auto in = BitView { msg.string_data.data(), msg.string_data.size() };
   auto result = parseStringTable(table, in, msg.num_entries);
   assert(in.eof());
   return result;
}

bool DemoParser::handleUpdateStringTable(const CSVCMsg_UpdateStringTable &msg)
{
   auto id = msg.table_id;
   auto stringTable = findStringTableByID(id);
   assert(stringTable);

   auto in = BitView { msg.string_data.data(), msg.string_data.size() };
   auto result = parseStringTable(*stringTable, in, msg.num_changed_entries);
   assert(in.eof());
   return result;
}

bool DemoParser::handleServerInfo(const CSVCMsg_ServerInfo &info)
{
   mServerInfo.protocol = info.protocol;
   mServerInfo.serverCount = info.server_count;
   mServerInfo.isDedicated = info.is_dedicated;
   mServerInfo.isHLTV = info.is_hltv;
   mServerInfo.isReplay = info.is_replay;
   mServerInfo.operatingSystem = static_cast<OperatingSystemType>(info.c_os);
   mServerInfo.crc.map = info.map_crc;
   mServerInfo.crc.client = info.client_crc;
   mServerInfo.crc.stringTable = info.string_table_crc;
   mServerInfo.maxClients = info.max_clients;
   mServerInfo.maxClasses = info.max_classes;
   mServerInfo.playerSlot = info.player_slot;
   mServerInfo.tickInterval = info.tick_interval;
   mServerInfo.gameDir = info.game_dir.to_string();
   mServerInfo.mapName = info.map_name.to_string();
   mServerInfo.skyName = info.sky_name.to_string();
   mServerInfo.hostName = info.host_name.to_string();
   mServerInfo.addonName = info.addon_name.to_string();
   mClassList.resize(mServerInfo.maxClasses);
   return true;
}

bool DemoParser::handleDemoSendTables(const CDemoSendTables &msg)
{
   ByteView bv { msg.data.data(), msg.data.size() };
   return parseSubMessage(bv);
}

bool DemoParser::handleDemoPacket(const CDemoPacket &msg)
{
   ByteView bv { msg.data.data(), msg.data.size() };
   return parseSubMessage(bv);
}

bool DemoParser::handleDemoFullPacket(const CDemoFullPacket &msg)
{
   bool success = true;
   success &= handleDemoPacket(msg.packet);

   if (mParseProfile && !mParseProfile->msg[DEM_StringTables]) {
      return success;
   }

   success &= handleDemoStringTables(msg.string_table);
   return success;
}

}
