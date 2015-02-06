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
#include "bitview.h"
#include "clientclass.h"
#include "demoparser.h"
#include "util.h"

namespace dota
{

bool DemoParser::parseMessage(BinaryStream &in)
{
   auto kind = in.readVarInt();
   auto comp = !!(kind & DEM_IsCompressed);
   auto tick = in.readVarInt();
   auto size = in.readVarInt();
   auto data = in.readArrayView<uint8_t>(size);

   // TODO: Reuse the decomp buffer so we don't have to reallocate every time
   auto decomp = std::vector<uint8_t> { };

   // Update tick?
   if (tick != mTick && kind != DEM_FileInfo) {
      onTick(tick);
      mTick = tick;
   }

   // Trim flags
   kind &= ~DEM_IsCompressed;

   // Skip filtered messages
   if (mParseProfile && !mParseProfile->msg[kind]) {
      in.skip(size);
      return true;
   }


   // Decompress with Snappy if needed
   if (comp) {
      if (!snappy::GetUncompressedLength(reinterpret_cast<const char*>(data.data()),
                                         data.size(),
                                         &size)) {
         return false;
      }

      decomp.resize(size);

      if (!snappy::RawUncompress(reinterpret_cast<const char*>(data.data()),
                                 data.size(),
                                 reinterpret_cast<char*>(decomp.data()))) {
         return false;
      }

      // Update our ArrayView to point to decompressed data
      data = decomp;
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

bool DemoParser::parseSubMessage(BinaryStream &in)
{
   while (!in.eof()) {
      auto kind = in.readVarInt();
      auto size = in.readVarInt();

      if (mParseProfile && !mParseProfile->sub[kind]) {
         in.skip(size);
         continue;
      }

      auto data = in.readArrayView<uint8_t>(size);

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
         decodeMessage<CSVCMsg_GameEvent>(data, &DemoParser::parseGameEvent);
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

struct static_string_buf : public std::streambuf
{
   static_string_buf(const static_string &str)
   {
      setg(str.data(), str.data(), str.data() + str.size());
   }
};

bool DemoParser::updateInstanceBaseline(EntityClass &entityClass, StringTable::Entry &baseline)
{
   auto in = BitView { baseline.userData.data(), baseline.userData.size() };
   auto propList = EntityPropList {};
   auto clientClass = entityClass.clientClass;
   propList.reserve(128);

   if (!clientClass) {
      // TODO: Slow path, dynamic entity with string map properties
      assert(false);
   }

   // Recreate the base instance
   if (entityClass.baseInstance) {
      clientClass->destroy(entityClass.baseInstance);
   }

   entityClass.baseInstance = clientClass->create();
   parseEntityPropList(in, propList);
   parseEntityProperties(in, entityClass, entityClass.baseInstance, propList);

   auto pos = in.getBufferPosition();
   auto length = baseline.userData.size();
   assert(pos + 1 >= length);
   return true;
}

bool DemoParser::addEntityClass(std::size_t id, std::string name, std::string tableName)
{
   assert(id < mClassList.size());
   auto &entityClass = mClassList[id];
   entityClass.id = id;
   entityClass.name = name;
   entityClass.tableName = tableName;
   entityClass.sendTable = findSendTableByName(entityClass.tableName);
   entityClass.clientClass = ClientClassList::get(entityClass.tableName);
   entityClass.clientClassID = entityClass.clientClass ? entityClass.clientClass->classID() : 0;
   mClassTableMap[entityClass.tableName] = &entityClass;
   return true;
}

bool DemoParser::handleDemoClassInfo(const CDemoClassInfo &msg)
{
   for (int i = 0; i < msg.classes_size(); ++i) {
      auto &cls = msg.classes(i);
      addEntityClass(cls.class_id(), cls.network_name(), cls.table_name());
   }

   return true;
}

bool DemoParser::handleClassInfo(const CSVCMsg_ClassInfo &msg)
{
   for (int i = 0; i < msg.classes_size(); ++i) {
      auto &cls = msg.classes(i);
      addEntityClass(cls.class_id(), cls.class_name(), cls.data_table_name());
   }

   return true;
}

bool DemoParser::handleDemoFileInfo(const CDemoFileInfo &info)
{
   auto game = info.game_info();
   auto dota = game.dota();

   mGameInfo.ticks = info.playback_ticks();
   mGameInfo.seconds = info.playback_time();
   mGameInfo.frames = info.playback_frames();

   mGameInfo.matchID = dota.match_id();
   mGameInfo.gameMode = dota.game_mode();
   mGameInfo.gameWinner = static_cast<TeamID>(dota.game_winner());
   mGameInfo.leagueID = dota.leagueid();
   mGameInfo.endTime = dota.end_time();
   mGameInfo.dire.id = dota.dire_team_id();
   mGameInfo.dire.tag = dota.dire_team_tag();
   mGameInfo.radiant.id = dota.radiant_team_id();
   mGameInfo.radiant.tag = dota.radiant_team_tag();

   mGameInfo.players.clear();
   mGameInfo.pickBans.clear();

   for (auto i = 0; i < dota.player_info_size(); ++i) {
      auto &player = dota.player_info(i);
      auto playerInfo = GameInfo::Player { };
      playerInfo.hero = player.hero_name();
      playerInfo.name = player.player_name();
      playerInfo.isFakeClient = player.is_fake_client();
      playerInfo.steamID = player.steamid();
      playerInfo.team = static_cast<TeamID>(player.game_team());
      mGameInfo.players.push_back(playerInfo);
   }

   for (auto i = 0; i < dota.picks_bans_size(); ++i) {
      auto &pickBan = dota.picks_bans(i);
      auto pickBanInfo = GameInfo::PickBan { };
      pickBanInfo.hero = pickBan.hero_id();
      pickBanInfo.team = static_cast<TeamID>(pickBan.team());
      pickBanInfo.type = static_cast<GameInfo::PickBanType>(pickBan.is_pick());
      mGameInfo.pickBans.push_back(pickBanInfo);
   }

   return true;
}

bool DemoParser::handleDemoSyncTick(const CDemoSyncTick &msg)
{
   auto &baseline = mStringTables["instancebaseline"];
   auto updateBaseline = (baseline.lastUpdate == mTick);

   // TODO: Lazy decode
   for (auto &&entityClass : mClassList) {
      if (entityClass.sendTable && entityClass.sendTable->needsDecode) {
         updateEntityClass(entityClass);
         entityClass.sendTable->needsDecode = false;
      }

      if (updateBaseline) {
         auto entry = baseline.findEntry(std::to_string(entityClass.id));

         if (entry) {
            updateInstanceBaseline(entityClass, *entry);
         }
      }
   }

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
   mFileHeader.demoFileStamp = header.demo_file_stamp();
   mFileHeader.networkProtocol = header.network_protocol();
   mFileHeader.serverName = header.server_name();
   mFileHeader.clientName = header.client_name();
   mFileHeader.mapName = header.map_name();
   mFileHeader.gameDirectory = header.game_directory();
   mFileHeader.fullpacketsVersion = header.fullpackets_version();
   mFileHeader.allowClientsideEntities = header.allow_clientside_entities();
   mFileHeader.allowClientsideParticles = header.allow_clientside_particles();
   return true;
}

bool DemoParser::handleSetConVar(const CNETMsg_SetConVar &msg)
{
   auto &convars = msg.convars();

   for (auto i = 0; i < convars.cvars_size(); ++i) {
      auto &cvar = convars.cvars(i);
      mConsoleVars[cvar.name()] = cvar.value();
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
   mSignonState.mapName = msg.map_name();
   mSignonState.numServerPlayers = msg.num_server_players();
   mSignonState.spawnCount = msg.spawn_count();
   mSignonState.state = static_cast<SignonState>(msg.signon_state());
   mSignonState.playerNetworkIDs.clear();

   for (auto i = 0; i < msg.players_networkids_size(); ++i) {
      mSignonState.playerNetworkIDs.push_back(msg.players_networkids(i));
   }

   return true;
}

bool DemoParser::handleSendTable(const CSVCMsg_SendTable &msg)
{
   auto name = msg.net_table_name();
   assert(!findSendTableByName(name));

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

   return true;
}

bool DemoParser::handleCreateStringTable(const CSVCMsg_CreateStringTable &msg)
{
   auto name = msg.name();
   assert(!findStringTableByName(name));

   auto &table = mStringTables[name];
   table.id = mStringTables.size() - 1;
   table.name = name;
   table.maxEntries = msg.max_entries();
   table.userDataFixedSize = msg.user_data_fixed_size();
   table.userDataSize = msg.user_data_size();
   table.userDataSizeBits = msg.user_data_size_bits();
   table.flags = msg.flags();
   table.entries.resize(table.maxEntries);

   auto &stringData = msg.string_data();
   auto in = BitView { stringData.data(), stringData.size() };
   auto result = parseStringTable(table, in, msg.num_entries());
   assert(in.getBufferPosition() == stringData.size());
   return result;
}

bool DemoParser::handleUpdateStringTable(const CSVCMsg_UpdateStringTable &msg)
{
   auto id = msg.table_id();
   auto stringTable = findStringTableByID(id);
   assert(stringTable);

   auto &stringData = msg.string_data();
   auto in = BitView { stringData.data(), stringData.size() };
   auto result = parseStringTable(*stringTable, in, msg.num_changed_entries());
   assert(in.getBufferPosition() == stringData.size());
   return result;
}

bool DemoParser::handleServerInfo(const CSVCMsg_ServerInfo &info)
{
   mServerInfo.protocol = info.protocol();
   mServerInfo.serverCount = info.server_count();
   mServerInfo.isDedicated = info.is_dedicated();
   mServerInfo.isHLTV = info.is_hltv();
   mServerInfo.isReplay = info.is_replay();
   mServerInfo.operatingSystem = static_cast<OperatingSystemType>(info.c_os());
   mServerInfo.crc.map = info.map_crc();
   mServerInfo.crc.client = info.client_crc();
   mServerInfo.crc.stringTable = info.string_table_crc();
   mServerInfo.maxClients = info.max_clients();
   mServerInfo.maxClasses = info.max_classes();
   mServerInfo.playerSlot = info.player_slot();
   mServerInfo.tickInterval = info.tick_interval();
   mServerInfo.gameDir = info.game_dir();
   mServerInfo.mapName = info.map_name();
   mServerInfo.skyName = info.sky_name();
   mServerInfo.hostName = info.host_name();
   mServerInfo.addonName = info.addon_name();

   mClassList.resize(mServerInfo.maxClasses);

   return true;
}

bool DemoParser::handleDemoPacket(const CDemoPacket &msg)
{
   auto binary = BinaryStream { msg.data().data(), msg.data().size() };
   return parseSubMessage(binary);
}

bool DemoParser::handleDemoFullPacket(const CDemoFullPacket &msg)
{
   bool success = true;
   success &= handleDemoPacket(msg.packet());

   if (mParseProfile && !mParseProfile->msg[DEM_StringTables]) {
      return success;
   }

   success &= handleDemoStringTables(msg.string_table());
   return success;
}

bool DemoParser::handleDemoSendTables(const CDemoSendTables &msg)
{
   auto binary = BinaryStream { msg.data().data(), msg.data().size() };
   return parseSubMessage(binary);
}

}
