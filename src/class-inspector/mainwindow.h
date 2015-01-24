#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "demoparser.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
   Q_OBJECT

public:
   explicit MainWindow(QWidget *parent = 0);
   ~MainWindow();

public slots:
   void classClicked(const QModelIndex &index);
   void onOpen();
   void onClose();
   void onExit();

protected:
   void showClassTreeList();
   void addClassProperties(class AbstractTreeItem *parent, std::vector<dota::Property> &properties);

private:
   Ui::MainWindow *ui;
   dota::DemoParser *mDemoParser;
};

#endif // MAINWINDOW_H
