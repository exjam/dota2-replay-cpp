#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "abstracttreemodel.h"

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

private:
   Ui::MainWindow *ui;
   AbstractTreeModel *mClassTreeModel;
   AbstractTreeModel *mDataTreeModel;
};

#endif // MAINWINDOW_H
