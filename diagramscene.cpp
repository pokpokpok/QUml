#include "diagramscene.h"
#include "event_handler/abstracteventhandler.h"
#include "event_handler/itemeventhandler.h"
#include "event_handler/selecteventhandler.h"
#include "event_handler/relationeventhandler.h"

DiagramScene::DiagramScene(QObject *parent) :
    QGraphicsScene(parent), mCountItemsId(0), mSceneState("NONE")
{
    setSceneRect(0, 0, 1000, 1000);

    mSceneEventHandlers.fill(0,(int)COUNT);
    mSceneEventHandlers[ITEM] = new ItemEventHandler(this);
    mSceneEventHandlers[SELECT] = new SelectEventHandler(this);
    mSceneEventHandlers[RELATION] = new RelationEventHandler(this);
    setSceneState("S_NONE");
}

DiagramScene::~DiagramScene()
{

}

void DiagramScene::setSceneState(const QString &newSceneState)
{
    mSceneState = newSceneState;

    SceneState mode;
    if(newSceneState[0] == 'I')
        mode = ITEM;
    else if(newSceneState[0] == 'S')
        mode = SELECT;
    else if(newSceneState[0] == 'R')
        mode = RELATION;

    mEventHandler = mSceneEventHandlers.at(mode);
}

void DiagramScene::saveSceneToFile(const QString &fileName)
{
    switch(mDiagType)
    {
    case ABSTRACT:
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
    case ABSTRACT:
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

void DiagramScene::addNewRelation(const QString &type)
{
    //NONE
}

void DiagramScene::addNewItem(const QString &newItemType, const QString &newItemName, const QPointF &newItemPos)
{
    switch(getDiagType())
    {
    case ABSTRACT:
        break;
    case USECASE:
        UseCaseItem *newItem = new UseCaseItem(mCountItemsId++, newItemType, newItemName, newItemPos, 0, this);
        connect(newItem, SIGNAL(sendIdToDel(int)), this, SLOT(deleteItem(int)));
        mItemsPtrList.append(newItem);
        break;
    }
}

void DiagramScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    mEventHandler->mouseDoubleClick(event);
//    if(!event->isAccepted())
        QGraphicsScene::mouseDoubleClickEvent(event);
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
