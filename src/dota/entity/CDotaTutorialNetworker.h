#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector3f.h"
#include <string>

namespace dota
{

struct DT_SpeechBubbleInfo
{
   std::string m_LocalizationStr;
   uint32_t m_hNPC;
   float m_flLifetime;
};

struct CDotaTutorialNetworker
{
   uint32_t m_nTutorialState;
   uint32_t m_nTaskProgress;
   uint32_t m_nTaskSteps;
   uint32_t m_nTaskSecondsRemianing;
   uint32_t m_nUIState;
   Vector3f m_TargetLocation;
   DT_SpeechBubbleInfo m_SpeechBubbles[4];
   uint32_t m_nLocationID;
};

DeclareClientStruct(DT_SpeechBubbleInfo);
DeclareClientClass(CDotaTutorialNetworker);

}
