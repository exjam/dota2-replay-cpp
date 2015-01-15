#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "binarystream.h"
#include "demoparser.h"
#include <iostream>
#include <fstream>
#include <QMap>

#include "entityclass.h"

class ClassTreeItem : public AbstractTreeItem
{
public:
   ClassTreeItem(dota::EntityClass *entityClass, AbstractTreeItem *parent = nullptr) :
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

   dota::EntityClass *getClass()
   {
      return mEntityClass;
   }

private:
   dota::EntityClass *mEntityClass;
};

QString getPropertyTypeName(dota::PropertyType type)
{
   static const QStringList names = {"Int", "Float", "Vector", "VectorXY", "String", "Array", "DataTable", "Int64"};
   return names.at(static_cast<int>(type));
}

QString getPropertyFlagName(dota::PropertyFlag flag)
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

QString getPropertyFlagsString(dota::PropertyFlag flags)
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

dota::DemoParser demo;
#include <iostream>

void addProperties(AbstractTreeItem *parent, std::vector<dota::Property> &properties)
{
   for (dota::Property &property : properties) {
      auto item = new PropertyTreeItem(&property);
      parent->addItem(item);

      if (property.isDataTable()) {
         auto itr = demo.mClassMap.find(property.dtName);

         if (itr != demo.mClassMap.end()) {
            item->setClassName(itr->second->name);
         }

         addProperties(item, demo.mSendTables[property.dtName].properties);
      }
   }
}

MainWindow::MainWindow(QWidget *parent) :
   QMainWindow(parent),
   ui(new Ui::MainWindow)
{
   ui->setupUi(this);

   auto file = std::ifstream { "1151921935.dem", std::ifstream::binary };
   auto in = BinaryStream { file };
   demo.parse(in);

   std::map<std::string, ClassTreeItem*> classTreeMap;
   std::vector<ClassTreeItem*> classTreeItems;

   dota::EntityClass *dotaPlayer = nullptr;

   auto classTreeRoot = new RootTreeItem(QStringList({"Class Name"}));
   mClassTreeModel = new AbstractTreeModel();
   mClassTreeModel->setRootItem(classTreeRoot);

   for (dota::EntityClass &cls : demo.mClassInfo) {
      auto item = new ClassTreeItem(&cls);

      if (cls.name.compare("CDOTAPlayer") == 0) {
         dotaPlayer = &cls;
      }

      classTreeItems.push_back(item);
      classTreeMap[cls.tableName] = item;
   }

   for (ClassTreeItem* cls : classTreeItems) {
      auto baseClass = cls->getClass()->getBaseClass();

      if (baseClass.size()) {
         auto itr = classTreeMap.find(baseClass);
         assert (itr != classTreeMap.end());
         itr->second->addItem(cls);
      }
   }

   for (ClassTreeItem* cls : classTreeItems) {
      if (cls->parent() == nullptr) {
         classTreeRoot->addItem(cls);
      }
   }

   ui->classTree->setModel(mClassTreeModel);
}

MainWindow::~MainWindow()
{
   delete ui;
}

void MainWindow::classClicked(const QModelIndex &index)
{
   AbstractTreeItem *item = static_cast<AbstractTreeItem*>(index.internalPointer());
   ClassTreeItem *classItem = reinterpret_cast<ClassTreeItem*>(item);

   auto dataRoot = new RootTreeItem(QStringList({"Name", "Type", "Flags"}));
   mDataTreeModel = new AbstractTreeModel();
   mDataTreeModel->setRootItem(dataRoot);

   addProperties(dataRoot, classItem->getClass()->sendTable->properties);

   ui->dataView->setModel(mDataTreeModel);

   ui->dataView->resizeColumnToContents(0);
   ui->dataView->resizeColumnToContents(1);
   ui->dataView->resizeColumnToContents(2);

   ui->dataView->setColumnWidth(0, 500);
   ui->dataView->setColumnWidth(1, ui->dataView->columnWidth(1) + 100);
   ui->dataView->setColumnWidth(2, ui->dataView->columnWidth(2) + 100);
}
