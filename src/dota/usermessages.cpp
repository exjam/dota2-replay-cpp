#include <iostream>

#include "demoparser.h"

#include "proto/usermessages.pbsl.h"
#include "proto/dota_usermessages.pbsl.h"

namespace dota
{

bool DemoParser::parseUserMessage(const CSVCMsg_UserMessage &message)
{
   auto kind = message.msg_type;

   // Skip filtered user messages
   if (mParseProfile && !mParseProfile->usr[kind]) {
      return true;
   }

   auto &data = message.msg_data;

   switch (kind) {
   case UM_SayText2:
      decodeMessage<CUserMsg_SayText2>(data, &DemoParser::handleSayText2);
      break;
   case DOTA_UM_AbilityPing:
      decodeMessage<CDOTAUserMsg_AbilityPing>(data, &DemoParser::handleAbilityPing);
      break;
   case DOTA_UM_AbilitySteal:
      decodeMessage<CDOTAUserMsg_AbilitySteal>(data, &DemoParser::handleAbilitySteal);
      break;
   case DOTA_UM_AIDebugLine:
      decodeMessage<CDOTAUserMsg_AIDebugLine>(data, &DemoParser::handleAIDebugLine);
      break;
   case DOTA_UM_BoosterState:
      decodeMessage<CDOTAUserMsg_BoosterState>(data, &DemoParser::handleBoosterState);
      break;
   case DOTA_UM_BotChat:
      decodeMessage<CDOTAUserMsg_BotChat>(data, &DemoParser::handleBotChat);
      break;
   case DOTA_UM_BuyBackStateAlert:
      decodeMessage<CDOTAUserMsg_BuyBackStateAlert>(data, &DemoParser::handleBuyBackStateAlert);
      break;
   case DOTA_UM_ChatEvent:
      decodeMessage<CDOTAUserMsg_ChatEvent>(data, &DemoParser::handleChatEvent);
      break;
   case DOTA_UM_ChatWheel:
      decodeMessage<CDOTAUserMsg_ChatWheel>(data, &DemoParser::handleChatWheel);
      break;
   case DOTA_UM_ClientLoadGridNav:
      decodeMessage<CDOTAUserMsg_ClientLoadGridNav>(data, &DemoParser::handleClientLoadGridNav);
      break;
   case DOTA_UM_CoachHUDPing:
      decodeMessage<CDOTAUserMsg_CoachHUDPing>(data, &DemoParser::handleCoachHUDPing);
      break;
   case DOTA_UM_CombatHeroPositions:
      decodeMessage<CDOTAUserMsg_CombatHeroPositions>(data, &DemoParser::handleCombatHeroPositions);
      break;
   case DOTA_UM_CombatLogShowDeath:
      decodeMessage<CDOTAUserMsg_CombatLogShowDeath>(data, &DemoParser::handleCombatLogShowDeath);
      break;
   case DOTA_UM_CourierKilledAlert:
      decodeMessage<CDOTAUserMsg_CourierKilledAlert>(data, &DemoParser::handleCourierKilledAlert);
      break;
   case DOTA_UM_CreateLinearProjectile:
      decodeMessage<CDOTAUserMsg_CreateLinearProjectile>(data, &DemoParser::handleCreateLinearProjectile);
      break;
   case DOTA_UM_CustomMsg:
      decodeMessage<CDOTAUserMsg_CustomMsg>(data, &DemoParser::handleCustomMsg);
      break;
   case DOTA_UM_DestroyLinearProjectile:
      decodeMessage<CDOTAUserMsg_DestroyLinearProjectile>(data, &DemoParser::handleDestroyLinearProjectile);
      break;
   case DOTA_UM_DodgeTrackingProjectiles:
      decodeMessage<CDOTAUserMsg_DodgeTrackingProjectiles>(data, &DemoParser::handleDodgeTrackingProjectiles);
      break;
   case DOTA_UM_EnemyItemAlert:
      decodeMessage<CDOTAUserMsg_EnemyItemAlert>(data, &DemoParser::handleEnemyItemAlert);
      break;
   case DOTA_UM_GamerulesStateChanged:
      decodeMessage<CDOTA_UM_GamerulesStateChanged>(data, &DemoParser::handleGamerulesStateChanged);
      break;
   case DOTA_UM_GlobalLightColor:
      decodeMessage<CDOTAUserMsg_GlobalLightColor>(data, &DemoParser::handleGlobalLightColor);
      break;
   case DOTA_UM_GlobalLightDirection:
      decodeMessage<CDOTAUserMsg_GlobalLightDirection>(data, &DemoParser::handleGlobalLightDirection);
      break;
   case DOTA_UM_HalloweenDrops:
      decodeMessage<CDOTAUserMsg_HalloweenDrops>(data, &DemoParser::handleHalloweenDrops);
      break;
   case DOTA_UM_HudError:
      decodeMessage<CDOTAUserMsg_HudError>(data, &DemoParser::handleHudError);
      break;
   case DOTA_UM_InvalidCommand:
      decodeMessage<CDOTAUserMsg_InvalidCommand>(data, &DemoParser::handleInvalidCommand);
      break;
   case DOTA_UM_ItemAlert:
      decodeMessage<CDOTAUserMsg_ItemAlert>(data, &DemoParser::handleItemAlert);
      break;
   case DOTA_UM_ItemFound:
      decodeMessage<CDOTAUserMsg_ItemFound>(data, &DemoParser::handleItemFound);
      break;
   case DOTA_UM_ItemPurchased:
      decodeMessage<CDOTAUserMsg_ItemPurchased>(data, &DemoParser::handleItemPurchased);
      break;
   case DOTA_UM_LocationPing:
      decodeMessage<CDOTAUserMsg_LocationPing>(data, &DemoParser::handleLocationPing);
      break;
   case DOTA_UM_MapLine:
      decodeMessage<CDOTAUserMsg_MapLine>(data, &DemoParser::handleMapLine);
      break;
   case DOTA_UM_MiniKillCamInfo:
      decodeMessage<CDOTAUserMsg_MiniKillCamInfo>(data, &DemoParser::handleMiniKillCamInfo);
      break;
   case DOTA_UM_MinimapDebugPoint:
      decodeMessage<CDOTAUserMsg_MinimapDebugPoint>(data, &DemoParser::handleMinimapDebugPoint);
      break;
   case DOTA_UM_MinimapEvent:
      decodeMessage<CDOTAUserMsg_MinimapEvent>(data, &DemoParser::handleMinimapEvent);
      break;
   case DOTA_UM_MiniTaunt:
      decodeMessage<CDOTAUserMsg_MiniTaunt>(data, &DemoParser::handleMiniTaunt);
      break;
   case DOTA_UM_NevermoreRequiem:
      decodeMessage<CDOTAUserMsg_NevermoreRequiem>(data, &DemoParser::handleNevermoreRequiem);
      break;
   case DOTA_UM_OverheadEvent:
      decodeMessage<CDOTAUserMsg_OverheadEvent>(data, &DemoParser::handleOverheadEvent);
      break;
   case DOTA_UM_ParticleManager:
      decodeMessage<CDOTAUserMsg_ParticleManager>(data, &DemoParser::handleParticleManager);
      break;
   case DOTA_UM_Ping:
      decodeMessage<CDOTAUserMsg_Ping>(data, &DemoParser::handlePing);
      break;
   case DOTA_UM_PlayerMMR:
      decodeMessage<CDOTAUserMsg_PlayerMMR>(data, &DemoParser::handlePlayerMMR);
      break;
   case DOTA_UM_PredictionResult:
      decodeMessage<CDOTAUserMsg_PredictionResult>(data, &DemoParser::handlePredictionResult);
      break;
   case DOTA_UM_QuickBuyAlert:
      decodeMessage<CDOTAUserMsg_QuickBuyAlert>(data, &DemoParser::handleQuickBuyAlert);
      break;
   case DOTA_UM_ReceivedXmasGift:
      decodeMessage<CDOTAUserMsg_ReceivedXmasGift>(data, &DemoParser::handleReceivedXmasGift);
      break;
   case DOTA_UM_SendFinalGold:
      decodeMessage<CDOTAUserMsg_SendFinalGold>(data, &DemoParser::handleSendFinalGold);
      break;
   case DOTA_UM_SendGenericToolTip:
      decodeMessage<CDOTAUserMsg_SendGenericToolTip>(data, &DemoParser::handleSendGenericToolTip);
      break;
   case DOTA_UM_SendRoshanPopup:
      decodeMessage<CDOTAUserMsg_SendRoshanPopup>(data, &DemoParser::handleSendRoshanPopup);
      break;
   case DOTA_UM_SendStatPopup:
      decodeMessage<CDOTAUserMsg_SendStatPopup>(data, &DemoParser::handleSendStatPopup);
      break;
   case DOTA_UM_SetNextAutobuyItem:
      decodeMessage<CDOTAUserMsg_SetNextAutobuyItem>(data, &DemoParser::handleSetNextAutobuyItem);
      break;
   case DOTA_UM_SharedCooldown:
      decodeMessage<CDOTAUserMsg_SharedCooldown>(data, &DemoParser::handleSharedCooldown);
      break;
   case DOTA_UM_ShowGenericPopup:
      decodeMessage<CDOTAUserMsg_ShowGenericPopup>(data, &DemoParser::handleShowGenericPopup);
      break;
   case DOTA_UM_ShowSurvey:
      decodeMessage<CDOTAUserMsg_ShowSurvey>(data, &DemoParser::handleShowSurvey);
      break;
   case DOTA_UM_SpectatorPlayerClick:
      decodeMessage<CDOTAUserMsg_SpectatorPlayerClick>(data, &DemoParser::handleSpectatorPlayerClick);
      break;
   case DOTA_UM_StatsMatchDetails:
      decodeMessage<CDOTAUserMsg_StatsMatchDetails>(data, &DemoParser::handleStatsMatchDetails);
      break;
   case DOTA_UM_SwapVerify:
      decodeMessage<CDOTAUserMsg_SwapVerify>(data, &DemoParser::handleSwapVerify);
      break;
   case DOTA_UM_TutorialFade:
      decodeMessage<CDOTAUserMsg_TutorialFade>(data, &DemoParser::handleTutorialFade);
      break;
   case DOTA_UM_TutorialFinish:
      decodeMessage<CDOTAUserMsg_TutorialFinish>(data, &DemoParser::handleTutorialFinish);
      break;
   case DOTA_UM_TutorialMinimapPosition:
      decodeMessage<CDOTAUserMsg_TutorialMinimapPosition>(data, &DemoParser::handleTutorialMinimapPosition);
      break;
   case DOTA_UM_TutorialPingMinimap:
      decodeMessage<CDOTAUserMsg_TutorialPingMinimap>(data, &DemoParser::handleTutorialPingMinimap);
      break;
   case DOTA_UM_TutorialRequestExp:
      decodeMessage<CDOTAUserMsg_TutorialRequestExp>(data, &DemoParser::handleTutorialRequestExp);
      break;
   case DOTA_UM_TutorialTipInfo:
      decodeMessage<CDOTAUserMsg_TutorialTipInfo>(data, &DemoParser::handleTutorialTipInfo);
      break;
   case DOTA_UM_UnitEvent:
      decodeMessage<CDOTAUserMsg_UnitEvent>(data, &DemoParser::handleUnitEvent);
      break;
   case DOTA_UM_UpdateSharedContent:
      decodeMessage<CDOTAUserMsg_UpdateSharedContent>(data, &DemoParser::handleUpdateSharedContent);
      break;
   case DOTA_UM_VoteEnd:
      decodeMessage<CDOTAUserMsg_VoteEnd>(data, &DemoParser::handleVoteEnd);
      break;
   case DOTA_UM_VoteStart:
      decodeMessage<CDOTAUserMsg_VoteStart>(data, &DemoParser::handleVoteStart);
      break;
   case DOTA_UM_VoteUpdate:
      decodeMessage<CDOTAUserMsg_VoteUpdate>(data, &DemoParser::handleVoteUpdate);
      break;
   case DOTA_UM_WillPurchaseAlert:
      decodeMessage<CDOTAUserMsg_WillPurchaseAlert>(data, &DemoParser::handleWillPurchaseAlert);
      break;
   case DOTA_UM_WorldLine:
      decodeMessage<CDOTAUserMsg_WorldLine>(data, &DemoParser::handleWorldLine);
      break;
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
      // We are not interested in any of these messages
      return true;
   case DOTA_UM_AddUnitToSelection:
   case DOTA_UM_CharacterSpeakConcept:
   case DOTA_UM_CombatLogData:
   case DOTA_UM_StatsHeroDetails:
   case DOTA_UM_TournamentDrop:
   default:
      // These dota user messages dont seem to have a matching structure
      std::cout << "Unhandled user-message type " << kind << std::endl;
      return false;
   }

   return true;
}

bool DemoParser::handleSayText2(const CUserMsg_SayText2 &msg)
{
   return false;
}

bool DemoParser::handleAbilityPing(const CDOTAUserMsg_AbilityPing& msg)
{
   return false;
}

bool DemoParser::handleAbilitySteal(const CDOTAUserMsg_AbilitySteal &msg)
{
   return false;
}

bool DemoParser::handleAIDebugLine(const CDOTAUserMsg_AIDebugLine& msg)
{
   return false;
}

bool DemoParser::handleBoosterState(const CDOTAUserMsg_BoosterState& msg)
{
   return false;
}

bool DemoParser::handleBotChat(const CDOTAUserMsg_BotChat& msg)
{
   return false;
}

bool DemoParser::handleBuyBackStateAlert(const CDOTAUserMsg_BuyBackStateAlert& msg)
{
   return false;
}

bool DemoParser::handleChatEvent(const CDOTAUserMsg_ChatEvent& msg)
{
   return false;
}

bool DemoParser::handleChatWheel(const CDOTAUserMsg_ChatWheel& msg)
{
   return false;
}

bool DemoParser::handleClientLoadGridNav(const CDOTAUserMsg_ClientLoadGridNav& msg)
{
   return false;
}

bool DemoParser::handleCoachHUDPing(const CDOTAUserMsg_CoachHUDPing& msg)
{
   return false;
}

bool DemoParser::handleCombatHeroPositions(const CDOTAUserMsg_CombatHeroPositions& msg)
{
   return false;
}

bool DemoParser::handleCombatLogShowDeath(const CDOTAUserMsg_CombatLogShowDeath& msg)
{
   return false;
}

bool DemoParser::handleCourierKilledAlert(const CDOTAUserMsg_CourierKilledAlert &msg)
{
   return true;
}

bool DemoParser::handleCreateLinearProjectile(const CDOTAUserMsg_CreateLinearProjectile& msg)
{
   return false;
}

bool DemoParser::handleCustomMsg(const CDOTAUserMsg_CustomMsg& msg)
{
   return false;
}

bool DemoParser::handleDestroyLinearProjectile(const CDOTAUserMsg_DestroyLinearProjectile& msg)
{
   return false;
}

bool DemoParser::handleDodgeTrackingProjectiles(const CDOTAUserMsg_DodgeTrackingProjectiles& msg)
{
   return false;
}

bool DemoParser::handleEnemyItemAlert(const CDOTAUserMsg_EnemyItemAlert& msg)
{
   return false;
}

bool DemoParser::handleGamerulesStateChanged(const CDOTA_UM_GamerulesStateChanged& msg)
{
   return false;
}

bool DemoParser::handleGlobalLightColor(const CDOTAUserMsg_GlobalLightColor& msg)
{
   return false;
}

bool DemoParser::handleGlobalLightDirection(const CDOTAUserMsg_GlobalLightDirection& msg)
{
   return false;
}

bool DemoParser::handleHalloweenDrops(const CDOTAUserMsg_HalloweenDrops& msg)
{
   return false;
}

bool DemoParser::handleHudError(const CDOTAUserMsg_HudError& msg)
{
   return false;
}

bool DemoParser::handleInvalidCommand(const CDOTAUserMsg_InvalidCommand& msg)
{
   return false;
}

bool DemoParser::handleItemAlert(const CDOTAUserMsg_ItemAlert& msg)
{
   return false;
}

bool DemoParser::handleItemFound(const CDOTAUserMsg_ItemFound& msg)
{
   return false;
}

bool DemoParser::handleItemPurchased(const CDOTAUserMsg_ItemPurchased& msg)
{
   return false;
}

bool DemoParser::handleLocationPing(const CDOTAUserMsg_LocationPing& msg)
{
   return false;
}

bool DemoParser::handleMapLine(const CDOTAUserMsg_MapLine& msg)
{
   return false;
}

bool DemoParser::handleMiniKillCamInfo(const CDOTAUserMsg_MiniKillCamInfo& msg)
{
   return false;
}

bool DemoParser::handleMinimapDebugPoint(const CDOTAUserMsg_MinimapDebugPoint& msg)
{
   return false;
}

bool DemoParser::handleMinimapEvent(const CDOTAUserMsg_MinimapEvent& msg)
{
   return false;
}

bool DemoParser::handleMiniTaunt(const CDOTAUserMsg_MiniTaunt& msg)
{
   return false;
}

bool DemoParser::handleNevermoreRequiem(const CDOTAUserMsg_NevermoreRequiem& msg)
{
   return false;
}

bool DemoParser::handleOverheadEvent(const CDOTAUserMsg_OverheadEvent& msg)
{
   return false;
}

bool DemoParser::handleParticleManager(const CDOTAUserMsg_ParticleManager& msg)
{
   return false;
}

bool DemoParser::handlePing(const CDOTAUserMsg_Ping& msg)
{
   return false;
}

bool DemoParser::handlePlayerMMR(const CDOTAUserMsg_PlayerMMR& msg)
{
   return false;
}

bool DemoParser::handlePredictionResult(const CDOTAUserMsg_PredictionResult& msg)
{
   return false;
}

bool DemoParser::handleQuickBuyAlert(const CDOTAUserMsg_QuickBuyAlert& msg)
{
   return false;
}

bool DemoParser::handleReceivedXmasGift(const CDOTAUserMsg_ReceivedXmasGift& msg)
{
   return false;
}

bool DemoParser::handleSendFinalGold(const CDOTAUserMsg_SendFinalGold& msg)
{
   return false;
}

bool DemoParser::handleSendGenericToolTip(const CDOTAUserMsg_SendGenericToolTip& msg)
{
   return false;
}

bool DemoParser::handleSendRoshanPopup(const CDOTAUserMsg_SendRoshanPopup& msg)
{
   return false;
}

bool DemoParser::handleSendStatPopup(const CDOTAUserMsg_SendStatPopup& msg)
{
   return false;
}

bool DemoParser::handleSetNextAutobuyItem(const CDOTAUserMsg_SetNextAutobuyItem& msg)
{
   return false;
}

bool DemoParser::handleSharedCooldown(const CDOTAUserMsg_SharedCooldown& msg)
{
   return false;
}

bool DemoParser::handleShowGenericPopup(const CDOTAUserMsg_ShowGenericPopup& msg)
{
   return false;
}

bool DemoParser::handleShowSurvey(const CDOTAUserMsg_ShowSurvey& msg)
{
   return false;
}

bool DemoParser::handleSpectatorPlayerClick(const CDOTAUserMsg_SpectatorPlayerClick& msg)
{
   return false;
}

bool DemoParser::handleStatsMatchDetails(const CDOTAUserMsg_StatsMatchDetails& msg)
{
   return false;
}

bool DemoParser::handleSwapVerify(const CDOTAUserMsg_SwapVerify& msg)
{
   return false;
}

bool DemoParser::handleTutorialFade(const CDOTAUserMsg_TutorialFade& msg)
{
   return false;
}

bool DemoParser::handleTutorialFinish(const CDOTAUserMsg_TutorialFinish& msg)
{
   return false;
}

bool DemoParser::handleTutorialMinimapPosition(const CDOTAUserMsg_TutorialMinimapPosition& msg)
{
   return false;
}

bool DemoParser::handleTutorialPingMinimap(const CDOTAUserMsg_TutorialPingMinimap& msg)
{
   return false;
}

bool DemoParser::handleTutorialRequestExp(const CDOTAUserMsg_TutorialRequestExp& msg)
{
   return false;
}

bool DemoParser::handleTutorialTipInfo(const CDOTAUserMsg_TutorialTipInfo& msg)
{
   return false;
}

bool DemoParser::handleUnitEvent(const CDOTAUserMsg_UnitEvent& msg)
{
   return false;
}

bool DemoParser::handleUpdateSharedContent(const CDOTAUserMsg_UpdateSharedContent& msg)
{
   return false;
}

bool DemoParser::handleVoteEnd(const CDOTAUserMsg_VoteEnd& msg)
{
   return false;
}

bool DemoParser::handleVoteStart(const CDOTAUserMsg_VoteStart& msg)
{
   return false;
}

bool DemoParser::handleVoteUpdate(const CDOTAUserMsg_VoteUpdate& msg)
{
   return false;
}

bool DemoParser::handleWillPurchaseAlert(const CDOTAUserMsg_WillPurchaseAlert& msg)
{
   return false;
}

bool DemoParser::handleWorldLine(const CDOTAUserMsg_WorldLine& msg)
{
   return false;
}

}
