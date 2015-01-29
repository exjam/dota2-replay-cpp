#pragma once
#include <map>
#include <vector>
#include <functional>

#include "entity.h"
#include "gameevent.h"
#include "parseprofile.h"
#include "property.h"
#include "sendtable.h"
#include "stringtable.h"
#include "types.h"

class BinaryStream;
class BitStream;

class CDemoClassInfo;
class CDemoConsoleCmd;
class CDemoFileHeader;
class CDemoFileInfo;
class CDemoFullPacket;
class CDemoPacket;
class CDemoSendTables;
class CDemoStringTables;
class CDemoSyncTick;

class CNETMsg_SetConVar;
class CNETMsg_SignonState;
class CNETMsg_StringCmd;
class CNETMsg_Tick;

class CSVCMsg_CreateStringTable;
class CSVCMsg_UpdateStringTable;
class CSVCMsg_PacketEntities;
class CSVCMsg_TempEntities;
class CSVCMsg_ServerInfo;
class CSVCMsg_SendTable;
class CSVCMsg_UserMessage;
class CSVCMsg_ClassInfo;
class CSVCMsg_GameEvent;
class CSVCMsg_GameEventList;

class CUserMsg_SayText2;

class CDOTAUserMsg_AbilitySteal;
class CDOTAUserMsg_AbilityPing;
class CDOTAUserMsg_AIDebugLine;
class CDOTAUserMsg_BoosterState;
class CDOTAUserMsg_BotChat;
class CDOTAUserMsg_BuyBackStateAlert;
class CDOTAUserMsg_ChatEvent;
class CDOTAUserMsg_ChatWheel;
class CDOTAUserMsg_ClientLoadGridNav;
class CDOTAUserMsg_CoachHUDPing;
class CDOTAUserMsg_CombatHeroPositions;
class CDOTAUserMsg_CombatLogShowDeath;
class CDOTAUserMsg_CourierKilledAlert;
class CDOTAUserMsg_CreateLinearProjectile;
class CDOTAUserMsg_CustomMsg;
class CDOTAUserMsg_DestroyLinearProjectile;
class CDOTAUserMsg_DodgeTrackingProjectiles;
class CDOTAUserMsg_EnemyItemAlert;
class CDOTA_UM_GamerulesStateChanged;
class CDOTAUserMsg_GlobalLightColor;
class CDOTAUserMsg_GlobalLightDirection;
class CDOTAUserMsg_HalloweenDrops;
class CDOTAUserMsg_HudError;
class CDOTAUserMsg_InvalidCommand;
class CDOTAUserMsg_ItemAlert;
class CDOTAUserMsg_ItemFound;
class CDOTAUserMsg_ItemPurchased;
class CDOTAUserMsg_LocationPing;
class CDOTAUserMsg_MapLine;
class CDOTAUserMsg_MiniKillCamInfo;
class CDOTAUserMsg_MinimapDebugPoint;
class CDOTAUserMsg_MinimapEvent;
class CDOTAUserMsg_MiniTaunt;
class CDOTAUserMsg_NevermoreRequiem;
class CDOTAUserMsg_OverheadEvent;
class CDOTAUserMsg_ParticleManager;
class CDOTAUserMsg_Ping;
class CDOTAUserMsg_PlayerMMR;
class CDOTAUserMsg_PredictionResult;
class CDOTAUserMsg_QuickBuyAlert;
class CDOTAUserMsg_ReceivedXmasGift;
class CDOTAUserMsg_SendFinalGold;
class CDOTAUserMsg_SendGenericToolTip;
class CDOTAUserMsg_SendRoshanPopup;
class CDOTAUserMsg_SendStatPopup;
class CDOTAUserMsg_SetNextAutobuyItem;
class CDOTAUserMsg_SharedCooldown;
class CDOTAUserMsg_ShowGenericPopup;
class CDOTAUserMsg_ShowSurvey;
class CDOTAUserMsg_SpectatorPlayerClick;
class CDOTAUserMsg_StatsMatchDetails;
class CDOTAUserMsg_SwapVerify;
class CDOTAUserMsg_TutorialFade;
class CDOTAUserMsg_TutorialFinish;
class CDOTAUserMsg_TutorialMinimapPosition;
class CDOTAUserMsg_TutorialPingMinimap;
class CDOTAUserMsg_TutorialRequestExp;
class CDOTAUserMsg_TutorialTipInfo;
class CDOTAUserMsg_UnitEvent;
class CDOTAUserMsg_UpdateSharedContent;
class CDOTAUserMsg_VoteEnd;
class CDOTAUserMsg_VoteStart;
class CDOTAUserMsg_VoteUpdate;
class CDOTAUserMsg_WillPurchaseAlert;
class CDOTAUserMsg_WorldLine;

namespace dota
{

enum class OperatingSystemType
{
   Linux = 'L',
   Windows = 'W'
};

enum class TeamID
{
   Radiant = 2,
   Dire = 3,
   Spectator = 5
};

enum class GameMode
{
   None,
   AllPick,
   CaptainsMode,
   RandomDraft,
   SingleDraft,
   AllRandom,
   Intro,
   Diretide,
   ReverseCaptainsMode,
   Greeviling,
   Tutorial,
   MidOnly,
   LeastPlayed,
   NewPlayerPool,
   Compendium
};

struct ServerInfo
{
   struct CrcTable {
      uint32_t map;
      uint32_t client;
      uint32_t stringTable;
   };

   int32_t protocol;
   int32_t serverCount;
   bool isDedicated;
   bool isHLTV;
   bool isReplay;
   OperatingSystemType operatingSystem;
   CrcTable crc;
   std::size_t maxClients;
   std::size_t maxClasses;
   std::size_t playerSlot;
   float tickInterval;
   std::string gameDir;
   std::string mapName;
   std::string skyName;
   std::string hostName;
   std::string addonName;
};

struct GameInfo {
   struct Team {
      uint32_t id;
      std::string tag;
   };

   struct Player {
      std::string hero;
      std::string name;
      bool isFakeClient;
      uint64_t steamID;
      TeamID team;
   };

   enum class PickBanType {
      Ban,
      Pick
   };

   struct PickBan {
      PickBanType type;
      TeamID team;
      uint32_t hero;
   };

   std::size_t ticks;
   std::size_t frames;
   std::size_t seconds;
   uint32_t matchID;
   uint32_t gameMode; // DOTA_GameMode ?
   TeamID gameWinner;
   uint32_t leagueID;
   std::size_t endTime;

   Team dire;
   Team radiant;

   std::vector<Player> players;
   std::vector<PickBan> pickBans;
};

struct FileHeader
{
   std::string demoFileStamp;
   int32_t networkProtocol;
   std::string serverName;
   std::string clientName;
   std::string mapName;
   std::string gameDirectory;
   int32_t fullpacketsVersion;
   bool allowClientsideEntities;
   bool allowClientsideParticles;
};


enum class SignonState
{
   None,
   Challenge,  // Client challenge server
   Connected,  // Client is connected to server
   New,        // Just got serverinfo and stringtables
   PreSpawn,   // Received signon buffers
   Spawn,      // Ready to receive entity packets
   Full,       // Fully connected, first non-delta packet received
   ChangeLevel // Server is changing level
};

struct SignonStateInfo
{
   std::string mapName;
   std::vector<std::string> playerNetworkIDs;
   std::size_t numServerPlayers;
   std::size_t spawnCount;
   SignonState state;
};

struct TickData
{
   std::vector<std::pair<GameEventDescriptor *, GameEvent *>> gameEvents;
   std::vector<Entity *> enterEntity;
   std::vector<EntityHandle> deleteEntity;
};

using SendTableMap = std::map<std::string, SendTable>;
using EntityPropList = std::vector<std::size_t>;
using ClassList = std::vector<EntityClass>;
using GameEventDescriptorList = std::vector<GameEventDescriptor>;

using TickEventListener = std::function<void(Tick,TickData&)>;

class DemoParser
{
public:
   bool parse(BinaryStream &in, const ParseProfile *profile = nullptr);

   const ServerInfo &serverInfo() const;
   const GameInfo &gameInfo() const;
   const FileHeader &fileHeader() const;
   const SignonStateInfo &signonState() const;
   const ClassList &classList() const;
   const GameEventDescriptorList &gameEventDescriptors() const;

   StringTable *findStringTableByID(int id);
   StringTable *findStringTableByName(const std::string &name);
   SendTable *findSendTableByName(const std::string &name);
   EntityClass *findClassByTableName(const std::string &name);

   void setOnTickEventListener(TickEventListener listener);

protected:
   bool parseMessage(BinaryStream &in);
   bool parseSubMessage(BinaryStream &in);

   template<typename Type, typename Handler>
   bool decodeMessage(const std::vector<uint8_t> &array, Handler handler)
   {
      Type message;

      if (!message.ParseFromArray(array.data(), array.size())) {
         return false;
      }

      return (this->*handler)(message);
   }

   template<typename Type, typename Handler>
   bool decodeMessage(const std::string &string, Handler handler)
   {
      Type message;

      if (!message.ParseFromString(string)) {
         return false;
      }

      return (this->*handler)(message);
   }

   void onTick(Tick tick);
   void onEntityEnter(Entity &entity);
   void onEntityDelete(Entity &entity);

   bool addEntityClass(std::size_t id, std::string name, std::string tableName);

   bool updateEntityClass(EntityClass &entityClass);
   bool updateInstanceBaseline(EntityClass &entityClass, StringTable::Entry &baseline);

   bool parseStringTable(StringTable &table, BitStream &in, std::size_t entries);
   bool parseEntityPropList(BitStream &in, EntityPropList &props);
   bool parseEntityProperties(BitStream &in, EntityClass &entityClass, ClientEntity *entity, EntityPropList &propList);

   bool handleDemoClassInfo(const CDemoClassInfo &info);
   bool handleDemoConsoleCmd(const CDemoConsoleCmd &cmd);
   bool handleDemoFileInfo(const CDemoFileInfo &info);
   bool handleDemoSyncTick(const CDemoSyncTick &msg);
   bool handleDemoFileHeader(const CDemoFileHeader &header);
   bool handleDemoPacket(const CDemoPacket &packet);
   bool handleDemoFullPacket(const CDemoFullPacket &packet);
   bool handleDemoSendTables(const CDemoSendTables &sendTables);
   bool handleDemoStringTables(const CDemoStringTables &stringTables);

   bool handleSignonState(const CNETMsg_SignonState &msg);
   bool handleTick(const CNETMsg_Tick &msg);
   bool handleStringCmd(const CNETMsg_StringCmd &msg);
   bool handleSetConVar(const CNETMsg_SetConVar &msg);

   bool parseUserMessage(const CSVCMsg_UserMessage &message);
   bool parseGameEvent(const CSVCMsg_GameEvent &event);
   bool parsePacketEntities(const CSVCMsg_PacketEntities &msg);
   bool parseTempEntities(const CSVCMsg_TempEntities &msg);

   bool handleSendTable(const CSVCMsg_SendTable &msg);
   bool handleClassInfo(const CSVCMsg_ClassInfo &msg);
   bool handleCreateStringTable(const CSVCMsg_CreateStringTable &msg);
   bool handleUpdateStringTable(const CSVCMsg_UpdateStringTable &msg);
   bool handleServerInfo(const CSVCMsg_ServerInfo &info);
   bool handleGameEventList(const CSVCMsg_GameEventList &list);

   bool handleSayText2(const CUserMsg_SayText2 &msg);

   bool handleAbilityPing(const CDOTAUserMsg_AbilityPing &msg);
   bool handleAbilitySteal(const CDOTAUserMsg_AbilitySteal &msg);
   bool handleAIDebugLine(const CDOTAUserMsg_AIDebugLine& msg);
   bool handleBoosterState(const CDOTAUserMsg_BoosterState& msg);
   bool handleBotChat(const CDOTAUserMsg_BotChat& msg);
   bool handleBuyBackStateAlert(const CDOTAUserMsg_BuyBackStateAlert& msg);
   bool handleChatEvent(const CDOTAUserMsg_ChatEvent& msg);
   bool handleChatWheel(const CDOTAUserMsg_ChatWheel& msg);
   bool handleClientLoadGridNav(const CDOTAUserMsg_ClientLoadGridNav& msg);
   bool handleCoachHUDPing(const CDOTAUserMsg_CoachHUDPing& msg);
   bool handleCombatHeroPositions(const CDOTAUserMsg_CombatHeroPositions& msg);
   bool handleCombatLogShowDeath(const CDOTAUserMsg_CombatLogShowDeath& msg);
   bool handleCourierKilledAlert(const CDOTAUserMsg_CourierKilledAlert &msg);
   bool handleCreateLinearProjectile(const CDOTAUserMsg_CreateLinearProjectile& msg);
   bool handleCustomMsg(const CDOTAUserMsg_CustomMsg& msg);
   bool handleDestroyLinearProjectile(const CDOTAUserMsg_DestroyLinearProjectile& msg);
   bool handleDodgeTrackingProjectiles(const CDOTAUserMsg_DodgeTrackingProjectiles& msg);
   bool handleEnemyItemAlert(const CDOTAUserMsg_EnemyItemAlert& msg);
   bool handleGamerulesStateChanged(const CDOTA_UM_GamerulesStateChanged& msg);
   bool handleGlobalLightColor(const CDOTAUserMsg_GlobalLightColor& msg);
   bool handleGlobalLightDirection(const CDOTAUserMsg_GlobalLightDirection& msg);
   bool handleHalloweenDrops(const CDOTAUserMsg_HalloweenDrops& msg);
   bool handleHudError(const CDOTAUserMsg_HudError& msg);
   bool handleInvalidCommand(const CDOTAUserMsg_InvalidCommand& msg);
   bool handleItemAlert(const CDOTAUserMsg_ItemAlert& msg);
   bool handleItemFound(const CDOTAUserMsg_ItemFound& msg);
   bool handleItemPurchased(const CDOTAUserMsg_ItemPurchased& msg);
   bool handleLocationPing(const CDOTAUserMsg_LocationPing& msg);
   bool handleMapLine(const CDOTAUserMsg_MapLine& msg);
   bool handleMiniKillCamInfo(const CDOTAUserMsg_MiniKillCamInfo& msg);
   bool handleMinimapDebugPoint(const CDOTAUserMsg_MinimapDebugPoint& msg);
   bool handleMinimapEvent(const CDOTAUserMsg_MinimapEvent& msg);
   bool handleMiniTaunt(const CDOTAUserMsg_MiniTaunt& msg);
   bool handleNevermoreRequiem(const CDOTAUserMsg_NevermoreRequiem& msg);
   bool handleOverheadEvent(const CDOTAUserMsg_OverheadEvent& msg);
   bool handleParticleManager(const CDOTAUserMsg_ParticleManager& msg);
   bool handlePing(const CDOTAUserMsg_Ping& msg);
   bool handlePlayerMMR(const CDOTAUserMsg_PlayerMMR& msg);
   bool handlePredictionResult(const CDOTAUserMsg_PredictionResult& msg);
   bool handleQuickBuyAlert(const CDOTAUserMsg_QuickBuyAlert& msg);
   bool handleReceivedXmasGift(const CDOTAUserMsg_ReceivedXmasGift& msg);
   bool handleSendFinalGold(const CDOTAUserMsg_SendFinalGold& msg);
   bool handleSendGenericToolTip(const CDOTAUserMsg_SendGenericToolTip& msg);
   bool handleSendRoshanPopup(const CDOTAUserMsg_SendRoshanPopup& msg);
   bool handleSendStatPopup(const CDOTAUserMsg_SendStatPopup& msg);
   bool handleSetNextAutobuyItem(const CDOTAUserMsg_SetNextAutobuyItem& msg);
   bool handleSharedCooldown(const CDOTAUserMsg_SharedCooldown& msg);
   bool handleShowGenericPopup(const CDOTAUserMsg_ShowGenericPopup& msg);
   bool handleShowSurvey(const CDOTAUserMsg_ShowSurvey& msg);
   bool handleSpectatorPlayerClick(const CDOTAUserMsg_SpectatorPlayerClick& msg);
   bool handleStatsMatchDetails(const CDOTAUserMsg_StatsMatchDetails& msg);
   bool handleSwapVerify(const CDOTAUserMsg_SwapVerify& msg);
   bool handleTutorialFade(const CDOTAUserMsg_TutorialFade& msg);
   bool handleTutorialFinish(const CDOTAUserMsg_TutorialFinish& msg);
   bool handleTutorialMinimapPosition(const CDOTAUserMsg_TutorialMinimapPosition& msg);
   bool handleTutorialPingMinimap(const CDOTAUserMsg_TutorialPingMinimap& msg);
   bool handleTutorialRequestExp(const CDOTAUserMsg_TutorialRequestExp& msg);
   bool handleTutorialTipInfo(const CDOTAUserMsg_TutorialTipInfo& msg);
   bool handleUnitEvent(const CDOTAUserMsg_UnitEvent& msg);
   bool handleUpdateSharedContent(const CDOTAUserMsg_UpdateSharedContent& msg);
   bool handleVoteEnd(const CDOTAUserMsg_VoteEnd& msg);
   bool handleVoteStart(const CDOTAUserMsg_VoteStart& msg);
   bool handleVoteUpdate(const CDOTAUserMsg_VoteUpdate& msg);
   bool handleWillPurchaseAlert(const CDOTAUserMsg_WillPurchaseAlert& msg);
   bool handleWorldLine(const CDOTAUserMsg_WorldLine& msg);

protected:
   Tick mTick;
   const ParseProfile *mParseProfile;

   ServerInfo mServerInfo;
   GameInfo mGameInfo;
   FileHeader mFileHeader;
   SignonStateInfo mSignonState;

   std::vector<EntityClass> mClassList;
   std::map<std::string, EntityClass*> mClassTableMap;
   SendTableMap mSendTables;
   std::map<std::string, StringTable> mStringTables;

   std::array<Entity, 2048> mEntities;

   GameEventDescriptorList mGameEventDescriptors;
   std::map<std::string, std::string> mConsoleVars;

   struct {
      TickEventListener onTick;
   } mEventListeners;

   TickData mTickData;
};

}
