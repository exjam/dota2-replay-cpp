#pragma once
#include "abstracttreemodel.h"
#include "entity.h"

class ClassTreeItem : public AbstractTreeItem
{
public:
   ClassTreeItem(const dota::EntityClass *entityClass, AbstractTreeItem *parent = nullptr) :
      AbstractTreeItem(parent),
      mEntityClass(entityClass)
   {
   }

   virtual ~ClassTreeItem()
   {
   }

   virtual QString data(int column) const Q_DECL_OVERRIDE
   {
      return QString::fromStdString(mEntityClass->name);
   }

   const dota::EntityClass *getClass()
   {
      return mEntityClass;
   }

private:
   const dota::EntityClass *mEntityClass;
};
