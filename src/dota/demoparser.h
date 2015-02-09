#pragma once
#include <map>
#include <vector>
#include <functional>
#include <string_view.h>

#include "entity.h"
#include "gameevent.h"
#include "parseprofile.h"
#include "property.h"
#include "sendtable.h"
#include "stringtable.h"
#include "types.h"

class BitView;
class ByteView;

struct CDemoClassInfo;
struct CDemoConsoleCmd;
struct CDemoFileHeader;
struct CDemoFileInfo;
struct CDemoFullPacket;
struct CDemoPacket;
struct CDemoSendTables;
struct CDemoStringTables;
struct CDemoSyncTick;

struct CNETMsg_SetConVar;
struct CNETMsg_SignonState;
struct CNETMsg_StringCmd;
struct CNETMsg_Tick;

struct CSVCMsg_CreateStringTable;
struct CSVCMsg_UpdateStringTable;
struct CSVCMsg_PacketEntities;
struct CSVCMsg_TempEntities;
struct CSVCMsg_ServerInfo;
struct CSVCMsg_SendTable;
struct CSVCMsg_UserMessage;
struct CSVCMsg_ClassInfo;
struct CSVCMsg_GameEvent;
struct CSVCMsg_GameEventList;

struct CUserMsg_SayText2;

struct CDOTAUserMsg_AbilitySteal;
struct CDOTAUserMsg_AbilityPing;
struct CDOTAUserMsg_AIDebugLine;
struct CDOTAUserMsg_BoosterState;
struct CDOTAUserMsg_BotChat;
struct CDOTAUserMsg_BuyBackStateAlert;
struct CDOTAUserMsg_ChatEvent;
struct CDOTAUserMsg_ChatWheel;
struct CDOTAUserMsg_ClientLoadGridNav;
struct CDOTAUserMsg_CoachHUDPing;
struct CDOTAUserMsg_CombatHeroPositions;
struct CDOTAUserMsg_CombatLogShowDeath;
struct CDOTAUserMsg_CourierKilledAlert;
struct CDOTAUserMsg_CreateLinearProjectile;
struct CDOTAUserMsg_CustomMsg;
struct CDOTAUserMsg_DestroyLinearProjectile;
struct CDOTAUserMsg_DodgeTrackingProjectiles;
struct CDOTAUserMsg_EnemyItemAlert;
struct CDOTA_UM_GamerulesStateChanged;
struct CDOTAUserMsg_GlobalLightColor;
struct CDOTAUserMsg_GlobalLightDirection;
struct CDOTAUserMsg_HalloweenDrops;
struct CDOTAUserMsg_HudError;
struct CDOTAUserMsg_InvalidCommand;
struct CDOTAUserMsg_ItemAlert;
struct CDOTAUserMsg_ItemFound;
struct CDOTAUserMsg_ItemPurchased;
struct CDOTAUserMsg_LocationPing;
struct CDOTAUserMsg_MapLine;
struct CDOTAUserMsg_MiniKillCamInfo;
struct CDOTAUserMsg_MinimapDebugPoint;
struct CDOTAUserMsg_MinimapEvent;
struct CDOTAUserMsg_MiniTaunt;
struct CDOTAUserMsg_NevermoreRequiem;
struct CDOTAUserMsg_OverheadEvent;
struct CDOTAUserMsg_ParticleManager;
struct CDOTAUserMsg_Ping;
struct CDOTAUserMsg_PlayerMMR;
struct CDOTAUserMsg_PredictionResult;
struct CDOTAUserMsg_QuickBuyAlert;
struct CDOTAUserMsg_ReceivedXmasGift;
struct CDOTAUserMsg_SendFinalGold;
struct CDOTAUserMsg_SendGenericToolTip;
struct CDOTAUserMsg_SendRoshanPopup;
struct CDOTAUserMsg_SendStatPopup;
struct CDOTAUserMsg_SetNextAutobuyItem;
struct CDOTAUserMsg_SharedCooldown;
struct CDOTAUserMsg_ShowGenericPopup;
struct CDOTAUserMsg_ShowSurvey;
struct CDOTAUserMsg_SpectatorPlayerClick;
struct CDOTAUserMsg_StatsMatchDetails;
struct CDOTAUserMsg_SwapVerify;
struct CDOTAUserMsg_TutorialFade;
struct CDOTAUserMsg_TutorialFinish;
struct CDOTAUserMsg_TutorialMinimapPosition;
struct CDOTAUserMsg_TutorialPingMinimap;
struct CDOTAUserMsg_TutorialRequestExp;
struct CDOTAUserMsg_TutorialTipInfo;
struct CDOTAUserMsg_UnitEvent;
struct CDOTAUserMsg_UpdateSharedContent;
struct CDOTAUserMsg_VoteEnd;
struct CDOTAUserMsg_VoteStart;
struct CDOTAUserMsg_VoteUpdate;
struct CDOTAUserMsg_WillPurchaseAlert;
struct CDOTAUserMsg_WorldLine;

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
   float seconds;
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
   bool parse(ByteView &in, const ParseProfile *profile = nullptr);

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
   bool parseMessage(ByteView &in);
   bool parseSubMessage(ByteView &in);

   template<typename MessageType, typename MessageHandler>
   bool decodeMessage(const std::string_view &data, MessageHandler handler)
   {
      MessageType message;

      if (!message.parse(data)) {
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

   bool parseStringTable(StringTable &table, BitView &in, std::size_t entries);
   bool parseEntityPropList(BitView &in, EntityPropList &props);
   bool parseEntityProperties(BitView &in, EntityClass &entityClass, ClientEntity *entity, EntityPropList &propList);

   bool handleDemoClassInfo(const CDemoClassInfo &msg);
   bool handleDemoConsoleCmd(const CDemoConsoleCmd &msg);
   bool handleDemoFileInfo(const CDemoFileInfo &msg);
   bool handleDemoSyncTick(const CDemoSyncTick &msg);
   bool handleDemoFileHeader(const CDemoFileHeader &msg);
   bool handleDemoPacket(const CDemoPacket &packet);
   bool handleDemoFullPacket(const CDemoFullPacket &msg);
   bool handleDemoSendTables(const CDemoSendTables &msg);
   bool handleDemoStringTables(const CDemoStringTables &msg);

   bool handleSignonState(const CNETMsg_SignonState &msg);
   bool handleTick(const CNETMsg_Tick &msg);
   bool handleStringCmd(const CNETMsg_StringCmd &msg);
   bool handleSetConVar(const CNETMsg_SetConVar &msg);

   bool parseUserMessage(const CSVCMsg_UserMessage &message);
   bool parsePacketEntities(const CSVCMsg_PacketEntities &msg);
   bool parseTempEntities(const CSVCMsg_TempEntities &msg);

   bool handleCreateStringTable(const CSVCMsg_CreateStringTable &msg);
   bool handleUpdateStringTable(const CSVCMsg_UpdateStringTable &msg);
   bool handleSendTable(const CSVCMsg_SendTable &msg);
   bool handleClassInfo(const CSVCMsg_ClassInfo &msg);
   bool handleServerInfo(const CSVCMsg_ServerInfo &msg);
   bool handleGameEvent(const CSVCMsg_GameEvent &msg);
   bool handleGameEventList(const CSVCMsg_GameEventList &msg);

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
