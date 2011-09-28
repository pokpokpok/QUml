#include "diagramscene.h"

DiagramScene::DiagramScene(QObject *parent) :
    QGraphicsScene(parent), mCountItemsId(0), mItemState("NONE")
{
    setSceneRect(0, 0, 1000, 1000);
}

DiagramScene::~DiagramScene()
{

}

void DiagramScene::saveSceneToFile(const QString &fileName)
{
    switch(mDiagType)
    {
    case NONE:
        break;
    case USECASE:
        UseCaseModel *useCaseModel = new UseCaseModel(this);
        useCaseModel->saveModel(fileName, mItemsPtrList);
        delete useCaseModel;
        break;
    }
}

void DiagramScene::openSceneFromFile(const QString &fileName)
{
    switch(mDiagType)
    {
    case NONE:
        break;
    case USECASE:
        UseCaseModel *useCaseModel = new UseCaseModel(this);
        connect(useCaseModel, SIGNAL(addNewItem(QString,QString,QPointF)), this, SLOT(addNewItem(QString,QString,QPointF)));
        useCaseModel->loadModel(fileName);
        delete useCaseModel;
        break;
    }
}

void DiagramScene::deleteItem(int itemIdToDel)
{
    for(int i(0); i < mItemsPtrList.size(); i++)
    {
        if(mItemsPtrList[i]->getItemId() == itemIdToDel)
        {
            removeItem(mItemsPtrList[i]);
            delete mItemsPtrList[i];
            mItemsPtrList.removeAt(i);
            break;
        }
    }
}

void DiagramScene::addNewItem(const QString &newItemType, const QString &newItemName, const QPointF &newItemPos)
{
    switch(mDiagType)
    {
    case NONE:
        break;
    case USECASE:
        UseCaseItem *newItem = new UseCaseItem(mCountItemsId++, newItemType, newItemName, newItemPos, 0, this);
        connect(newItem, SIGNAL(sendIdToDel(int)), this, SLOT(deleteItem(int)));
        mItemsPtrList.append(newItem);
        break;
    }
}

void DiagramScene::addNewRelation(const QString &type)
{
    //NONE
}

void DiagramScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton && mItemState != "NONE")
    {
        addNewItem(mItemState, "", event->scenePos());
    }
}

void DiagramScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mousePressEvent(event);
}

void DiagramScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseMoveEvent(event);
}

void DiagramScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseReleaseEvent(event);
}
