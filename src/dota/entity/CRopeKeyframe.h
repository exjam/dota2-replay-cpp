#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector3f.h"

namespace dota
{

struct CRopeKeyframe
{
   uint32_t m_hStartPoint;
   uint32_t m_hEndPoint;
   int32_t m_iStartAttachment;
   int32_t m_iEndAttachment;
   int32_t m_Slack;
   int32_t m_RopeLength;
   uint32_t m_fLockedPoints;
   uint32_t m_nChangeCount;
   uint32_t m_RopeFlags;
   uint32_t m_nSegments;
   uint32_t m_bConstrainBetweenEndpoints;
   uint32_t m_iRopeMaterialModelIndex;
   uint32_t m_Subdiv;
   float m_TextureScale;
   float m_Width;
   float m_flScrollSpeed;
   Vector3f m_vecOrigin;
   uint32_t moveparent;
   uint32_t m_iParentAttachment;
   uint32_t m_nMinCPULevel;
   uint32_t m_nMaxCPULevel;
   uint32_t m_nMinGPULevel;
   uint32_t m_nMaxGPULevel;
};

DeclareClientClass(CRopeKeyframe);

}
