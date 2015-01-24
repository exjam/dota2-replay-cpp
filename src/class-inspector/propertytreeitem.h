#pragma once
#include "abstracttreemodel.h"
#include "entity.h"

class PropertyTreeItem : public AbstractTreeItem
{
public:
   PropertyTreeItem(dota::Property *property, AbstractTreeItem *parent = nullptr) :
      AbstractTreeItem(parent),
      mProperty(property)
   {
   }

   virtual ~PropertyTreeItem()
   {
   }

   void setClassName(std::string className)
   {
      mClassName = className;
   }

   QString getPropertyTypeName(dota::PropertyType type) const
   {
      static const QStringList names = {
         "Int", "Float", "Vector", "VectorXY",
         "String", "Array", "DataTable", "Int64"
      };

      return names.at(static_cast<int>(type));
   }

   QString getPropertyFlagName(dota::PropertyFlag flag) const
   {
      switch(flag)
      {
      case dota::PropertyFlag::Unsigned:
         return "Unsigned";
      case dota::PropertyFlag::Coord:
         return "Coord";
      case dota::PropertyFlag::NoScale:
         return "NoScale";
      case dota::PropertyFlag::RoundDown:
         return "RoundDown";
      case dota::PropertyFlag::RoundUp:
         return "RoundUp";
      case dota::PropertyFlag::Normal:
         return "Normal";
      case dota::PropertyFlag::Exclude:
         return "Exclude";
      case dota::PropertyFlag::Xyze:
         return "Xyze";
      case dota::PropertyFlag::InsideArray:
         return "InsideArray";
      case dota::PropertyFlag::ProxyAlways:
         return "ProxyAlways";
      case dota::PropertyFlag::VectorElem:
         return "VectorElem";
      case dota::PropertyFlag::Collapsible:
         return "Collapsible";
      case dota::PropertyFlag::CoordMp:
         return "CoordMp";
      case dota::PropertyFlag::CoordMpLowPrecision:
         return "CoordMpLowPrecision";
      case dota::PropertyFlag::CoordMpIntegral:
         return "CoordMpIntegral";
      case dota::PropertyFlag::CellCoord:
         return "CellCoord";
      case dota::PropertyFlag::CellCoordLowPrecision:
         return "CellCoordLowPrecision";
      case dota::PropertyFlag::CellCoordIntegral:
         return "CellCoordIntegral";
      case dota::PropertyFlag::ChangesOften:
         return "ChangesOften";
      case dota::PropertyFlag::EncodedAgainstTickCount:
         return "EncodedAgainstTickCount";
      }

      return "";
   }

   QString getPropertyFlagsString(dota::PropertyFlag flags) const
   {
      QStringList flagNames;

      for (uint32_t i = 0; i < 32; ++i) {
         dota::PropertyFlag flag = static_cast<dota::PropertyFlag>(1 << i);

         if (flags & flag) {
            flagNames.append(getPropertyFlagName(flag));
         }
      }

      return flagNames.join(",");
   }

   virtual QString data(int column) const Q_DECL_OVERRIDE
   {
      switch (column) {
      case 0:
         if (mProperty->isDataTable() && mClassName.size()) {
            return QString::fromStdString(mClassName);
         } else {
            return QString::fromStdString(mProperty->varName);
         }
      case 1:
         return getPropertyTypeName(mProperty->type);
      case 2:
         return getPropertyFlagsString(mProperty->flags);
      default:
         return "";
      }
   }

private:
   std::string mClassName;
   dota::Property *mProperty;
};
