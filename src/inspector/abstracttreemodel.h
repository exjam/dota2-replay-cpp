#ifndef CLASSMODEL_H
#define CLASSMODEL_H

#include <QObject>
#include <QAbstractItemModel>

class AbstractTreeItem
{
public:
   AbstractTreeItem(AbstractTreeItem *parent = nullptr) :
      mParent(parent)
   {
      if (parent) {
         parent->addItem(this);
      }
   }

   virtual ~AbstractTreeItem()
   {
      for (auto &&item : mChildren) {
         delete item;
      }
   }

   virtual QString data(int column) const = 0;

   int row() const
   {
      if (mParent) {
         return mParent->mChildren.indexOf(const_cast<AbstractTreeItem*>(this));
      }

      return 0;
   }

   void addItem(AbstractTreeItem *child)
   {
      child->mParent = this;
      mChildren.append(child);
   }

   int childCount() const
   {
      return mChildren.size();
   }

   AbstractTreeItem *child(int index)
   {
      return mChildren.at(index);
   }

   AbstractTreeItem *parent()
   {
      return mParent;
   }

private:
   AbstractTreeItem *mParent;
   QList<AbstractTreeItem*> mChildren;
};

class RootTreeItem : public AbstractTreeItem
{
public:
   RootTreeItem(QStringList columnNames) :
      mColumnNames(columnNames)
   {

   }

   virtual ~RootTreeItem()
   {
   }

   int columnCount()
   {
      return mColumnNames.size();
   }

   virtual QString data(int column) const Q_DECL_OVERRIDE
   {
      return mColumnNames.at(column);
   }

   QStringList mColumnNames;
};

class AbstractTreeModel : public QAbstractItemModel
{
   Q_OBJECT
public:
   AbstractTreeModel(QObject *parent = nullptr);
   ~AbstractTreeModel();

   void setRootItem(RootTreeItem *root);

   QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
   Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;
   QVariant headerData(int section, Qt::Orientation orientation,
                       int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
   QModelIndex index(int row, int column,
                     const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
   QModelIndex parent(const QModelIndex &index) const Q_DECL_OVERRIDE;
   int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
   int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

private:
   RootTreeItem *mRoot;
};

#endif // CLASSMODEL_H
