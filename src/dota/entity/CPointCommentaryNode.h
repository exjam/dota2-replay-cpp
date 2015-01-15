#pragma once
#include <cstdint>
#include "networkclass.h"
#include <string>
#include "CBaseAnimating.h"

namespace dota
{

struct CPointCommentaryNode : public CBaseAnimating
{
   uint32_t m_bActive;
   std::string m_iszCommentaryFile;
   std::string m_iszCommentaryFileNoHDR;
   float m_flStartTime;
   std::string m_iszSpeakers;
   uint32_t m_iNodeNumber;
   uint32_t m_iNodeNumberMax;
   uint32_t m_hViewPosition;
};

DeclareNetworkClass(CPointCommentaryNode);

}
