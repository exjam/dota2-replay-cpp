#include "abstracttreemodel.h"

AbstractTreeModel::AbstractTreeModel(QObject *parent) :
   QAbstractItemModel(parent),
   mRoot(nullptr)
{
}

AbstractTreeModel::~AbstractTreeModel()
{
   delete mRoot;
}

int AbstractTreeModel::columnCount(const QModelIndex &parent) const
{
   if (mRoot) {
      return mRoot->columnCount();
   } else {
      return 0;
   }
}

void AbstractTreeModel::setRootItem(RootTreeItem *root)
{
   emit dataChanged(index(0, 0), index(rowCount() - 1, columnCount() - 1));
   delete mRoot;
   mRoot = root;
   emit dataChanged(index(0, 0), index(rowCount() - 1, columnCount() - 1));
}

QVariant AbstractTreeModel::data(const QModelIndex &index, int role) const
{
   if (!index.isValid())
      return QVariant();

   if (role != Qt::DisplayRole)
    return QVariant();

   AbstractTreeItem *item = static_cast<AbstractTreeItem*>(index.internalPointer());
   return item->data(index.column());
}

Qt::ItemFlags AbstractTreeModel::flags(const QModelIndex &index) const
{
   if (!index.isValid())
      return 0;

   return QAbstractItemModel::flags(index);
}

QVariant AbstractTreeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
   if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
      return mRoot->data(section);

   return QVariant();
}

QModelIndex AbstractTreeModel::index(int row, int column, const QModelIndex &parent)
            const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    AbstractTreeItem *parentItem;

    if (!parent.isValid())
        parentItem = mRoot;
    else
        parentItem = static_cast<AbstractTreeItem*>(parent.internalPointer());

    AbstractTreeItem *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}

QModelIndex AbstractTreeModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    AbstractTreeItem *childItem = static_cast<AbstractTreeItem*>(index.internalPointer());
    AbstractTreeItem *parentItem = childItem->parent();

    if (parentItem == mRoot)
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}

int AbstractTreeModel::rowCount(const QModelIndex &parent) const
{
    AbstractTreeItem *parentItem;

    if (!mRoot)
       return 0;

    if (parent.column() > 0)
       return 0;

    if (!parent.isValid())
       parentItem = mRoot;
    else
       parentItem = static_cast<AbstractTreeItem*>(parent.internalPointer());

    return parentItem->childCount();
}
