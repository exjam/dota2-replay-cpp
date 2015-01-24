#include <iostream>
#include <fstream>
#include <QFileDialog>
#include <QMap>
#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "classtreeitem.h"
#include "propertytreeitem.h"

#include "binarystream.h"
#include "demoparser.h"
#include "parseprofile.h"

MainWindow::MainWindow(QWidget *parent) :
   QMainWindow(parent),
   ui(new Ui::MainWindow),
   mDemoParser(nullptr)
{
   ui->setupUi(this);
}

MainWindow::~MainWindow()
{
   delete ui;
}

void MainWindow::onOpen()
{
   QString fileName = QFileDialog::getOpenFileName(this, tr("Open Replay"), QString(), tr("Demo Files (*.dem)"));

   if (!fileName.length()) {
      return;
   }

   auto file = std::ifstream { fileName.toStdString(), std::ifstream::binary };

   if (!file.is_open()) {
      return;
   }

   delete mDemoParser;
   mDemoParser = new dota::DemoParser();

   if (!mDemoParser->parse(BinaryStream { file }, dota::ParseProfile::SendTables)) {
      QMessageBox::warning(this, "Error", "Error parsing replay file");
      delete mDemoParser;
      mDemoParser = nullptr;
   } else {
      onClose();
      showClassTreeList();
   }
}

void MainWindow::showClassTreeList()
{
   auto classMap = std::map<std::string, ClassTreeItem*> {};
   auto items = std::vector<ClassTreeItem*> {};
   auto root = new RootTreeItem(QStringList({"Class Name"}));

   // Create list of all items
   for (auto &entityClass : mDemoParser->classList()) {
      auto item = new ClassTreeItem(&entityClass);
      items.push_back(item);
      classMap[entityClass.tableName] = item;
   }

   // Create tree from item list
   for (ClassTreeItem* item : items) {
      auto baseClass = item->getClass()->getBaseClass();

      if (baseClass.size()) {
         auto itr = classMap.find(baseClass);
         assert (itr != classMap.end());
         itr->second->addItem(item);
      }
   }

   // Add all base classes to tree root
   for (ClassTreeItem* item : items) {
      if (item->parent() == nullptr) {
         root->addItem(item);
      }
   }

   auto model = new AbstractTreeModel();
   model->setRootItem(root);
   delete ui->classTree->model();
   ui->classTree->setModel(model);
}

void MainWindow::onClose()
{
   delete ui->classTree->model();
   delete ui->dataView->model();
   ui->classTree->setModel(nullptr);
   ui->dataView->setModel(nullptr);
}

void MainWindow::onExit()
{
   QApplication::quit();
}

void MainWindow::addClassProperties(AbstractTreeItem *parent, std::vector<dota::Property> &properties)
{
   for (auto &property : properties) {
      auto item = new PropertyTreeItem(&property);
      parent->addItem(item);

      if (property.isDataTable()) {
         auto entityClass = mDemoParser->findClassByTableName(property.dtName);

         if (entityClass) {
            item->setClassName(entityClass->name);
         }

         addClassProperties(item, mDemoParser->findSendTableByName(property.dtName)->properties);
      }
   }
}

void MainWindow::classClicked(const QModelIndex &index)
{
   AbstractTreeItem *item = static_cast<AbstractTreeItem*>(index.internalPointer());
   ClassTreeItem *classItem = reinterpret_cast<ClassTreeItem*>(item);

   auto dataRoot = new RootTreeItem(QStringList({"Name", "Type", "Flags"}));
   addClassProperties(dataRoot, classItem->getClass()->sendTable->properties);

   auto model = new AbstractTreeModel();
   model->setRootItem(dataRoot);
   delete ui->dataView->model();
   ui->dataView->setModel(model);

   ui->dataView->resizeColumnToContents(0);
   ui->dataView->resizeColumnToContents(1);
   ui->dataView->resizeColumnToContents(2);

   ui->dataView->setColumnWidth(0, 500);
   ui->dataView->setColumnWidth(1, ui->dataView->columnWidth(1) + 100);
   ui->dataView->setColumnWidth(2, ui->dataView->columnWidth(2) + 100);
}
