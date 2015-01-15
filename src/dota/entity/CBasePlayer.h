#pragma once
#include <cstdint>
#include "networkclass.h"
#include "vector2f.h"
#include "vector3f.h"
#include <string>
#include <vector>
#include "CBaseCombatCharacter.h"

namespace dota
{

struct DT_PlayerState
{
   uint32_t deadflag;
};

struct DT_Local
{
   uint32_t m_chAreaBits[32];
   uint32_t m_chAreaPortalBits[24];
   uint32_t m_iHideHUD;
   float m_flFOVRate;
   uint32_t m_bDucked;
   uint32_t m_bDucking;
   uint32_t m_bInDuckJump;
   uint32_t m_nDuckTimeMsecs;
   uint32_t m_nDuckJumpTimeMsecs;
   uint32_t m_nJumpTimeMsecs;
   float m_flFallVelocity;
   Vector3f m_vecPunchAngle;
   Vector3f m_vecPunchAngleVel;
   uint32_t m_bDrawViewmodel;
   uint32_t m_bWearingSuit;
   uint32_t m_bPoisoned;
   float m_flStepSize;
   uint32_t m_bAllowAutoMovement;
   struct {
      int32_t scale;
      Vector3f origin;
      uint32_t area;
      struct {
         uint32_t enable;
         uint32_t blend;
         Vector3f dirPrimary;
         uint32_t colorPrimary;
         uint32_t colorSecondary;
         float start;
         float end;
         float maxdensity;
         float HDRColorScale;
      } fog;
   } m_skybox3d;
   struct {
      Vector3f localSound[8];
      int32_t soundscapeIndex;
      uint32_t localBits;
      int32_t entIndex;
   } m_audio;
};

struct DT_LocalPlayerExclusive
{
   DT_Local m_Local;
   Vector3f m_vecViewOffset;
   float m_flFriction;
   uint32_t m_iAmmo[32];
   uint32_t m_fOnTarget;
   int32_t m_nTickBase;
   int32_t m_nNextThinkTick;
   uint32_t m_hLastWeapon;
   Vector3f m_vecVelocity;
   Vector3f m_vecBaseVelocity;
   uint32_t m_hConstraintEntity;
   Vector3f m_vecConstraintCenter;
   float m_flConstraintRadius;
   float m_flConstraintWidth;
   float m_flConstraintSpeedFactor;
   uint32_t m_bConstraintPastRadius;
   float m_flDeathTime;
   uint32_t m_nWaterLevel;
   float m_flLaggedMovementValue;
   uint32_t m_hTonemapController;
};

struct CBasePlayer : public CBaseCombatCharacter
{
   DT_PlayerState pl;
   uint32_t m_hVehicle;
   uint32_t m_hUseEntity;
   uint32_t m_hGroundEntity;
   uint32_t m_iHealth;
   uint32_t m_lifeState;
   int32_t m_iBonusProgress;
   int32_t m_iBonusChallenge;
   float m_flMaxspeed;
   uint32_t m_fFlags;
   uint32_t m_iObserverMode;
   uint32_t m_hObserverTarget;
   uint32_t m_iFOV;
   uint32_t m_iFOVStart;
   float m_flFOVTime;
   uint32_t m_iDefaultFOV;
   uint32_t m_hZoomOwner;
   std::vector<uint32_t> m_hViewModel;
   std::string m_szLastPlaceName;
   Vector3f m_vecLadderNormal;
   uint32_t m_ladderSurfaceProps;
   uint32_t m_hPostProcessCtrl;
   uint32_t m_hColorCorrectionCtrl;
   struct {
      uint32_t m_hCtrl;
   } m_PlayerFog;
   uint32_t m_currentSCLPacked;
   uint32_t m_hViewEntity;
   DT_LocalPlayerExclusive localdata;
};

DeclareNetworkStruct(DT_PlayerState);
DeclareNetworkStruct(DT_Local);
DeclareNetworkStruct(DT_LocalPlayerExclusive);
DeclareNetworkClass(CBasePlayer);

}
