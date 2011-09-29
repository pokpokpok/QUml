#include "event_handler/itemeventhandler.h"
#include "usecase_diagram/usecaseitem.h"

ItemEventHandler::ItemEventHandler(DiagramScene *parent) :
    AbstractEventHandler(parent)
{

}

ItemEventHandler::~ItemEventHandler()
{

}

void ItemEventHandler::mouseDoubleClick(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton && mDiagScene->getSceneState() != "S_NONE")
    {
        mDiagScene->addNewItem(mDiagScene->getSceneState(), "", event->scenePos());
    }
}

void ItemEventHandler::mousePress(QGraphicsSceneMouseEvent *event)
{

}

void ItemEventHandler::mouseMove(QGraphicsSceneMouseEvent *event)
{

}

void ItemEventHandler::mouseRelease(QGraphicsSceneMouseEvent *event)
{

}
