#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector3f.h"
#include "CBaseAnimating.h"

namespace dota
{

struct CPropVehicleDriveable : public CBaseAnimating
{
   uint32_t m_hPlayer;
   int32_t m_nSpeed;
   int32_t m_nRPM;
   float m_flThrottle;
   int32_t m_nBoostTimeLeft;
   uint32_t m_nHasBoost;
   uint32_t m_nScannerDisabledWeapons;
   uint32_t m_nScannerDisabledVehicle;
   uint32_t m_bEnterAnimOn;
   uint32_t m_bExitAnimOn;
   uint32_t m_bUnableToFire;
   Vector3f m_vecEyeExitEndpoint;
   uint32_t m_bHasGun;
   Vector3f m_vecGunCrosshair;
};

DeclareClientClass(CPropVehicleDriveable);

}
