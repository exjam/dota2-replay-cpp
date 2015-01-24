#pragma once
#include <cstdint>
#include "clientclass.h"
#include "vector3f.h"
#include "CRagdollProp.h"

namespace dota
{

struct CRagdollPropAttached : public CRagdollProp
{
   uint32_t m_boneIndexAttached;
   uint32_t m_ragdollAttachedObjectIndex;
   Vector3f m_attachmentPointBoneSpace;
   Vector3f m_attachmentPointRagdollSpace;
};

DeclareClientClass(CRagdollPropAttached);

}
