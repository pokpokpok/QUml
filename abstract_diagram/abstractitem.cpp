#include "abstract_diagram/abstractitem.h"

#include <QtGui/QAction>
#include <QtGui/QMenu>
#include <QtGui/QGraphicsSceneContextMenuEvent>
#include <QtCore/QDebug>
#include <QtGui/QGraphicsScene>
#include <QtGui/QPainter>
#include <math.h>

AbstractItem::AbstractItem(int newItemId, const QString &newItemType,
                           const QString &newItemName, const QPointF &newItemPos,
                           QGraphicsItem *parent, QGraphicsScene *scene)
    : QGraphicsPolygonItem(parent, scene), mItemRectF(0, 0, 100, 62.5)
{
    mItemId = newItemId;
    mItemType = newItemType;
    mItemName = newItemName;
    setPos(newItemPos);
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    setAcceptHoverEvents(true);
    initializeContextMenu();
}

void AbstractItem::setItemName(const QString &newItemName)
{
    mItemName = newItemName;
    paintItemMembers();
}

void AbstractItem::initializeContextMenu()
{
    mItemMenu = new QMenu();
    mEditAction = mItemMenu->addAction(tr("&Edit"));
    connect(mEditAction, SIGNAL(triggered()), this, SLOT(editActionSlot()));
    mDownZValueAction = mItemMenu->addAction(tr("&Down"));
    connect(mDownZValueAction, SIGNAL(triggered()), this, SLOT(downZValueActionSlot()));
    mUpZValueAction = mItemMenu->addAction(tr("&Up"));
    connect(mUpZValueAction, SIGNAL(triggered()), this, SLOT(upZValueActionSlot()));
    mDeleteAction = mItemMenu->addAction(tr("&Delete"));
//    this->deleteAction->setShortcut(Qt::Key_Delete);
    connect(mDeleteAction, SIGNAL(triggered()), this, SLOT(deleteActionSlot()));
}

void AbstractItem::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    scene()->clearSelection();
    setSelected(true);
    mItemMenu->exec(event->screenPos());
}

void AbstractItem::deleteActionSlot()
{
    emit sendIdToDel(mItemId);
}

void AbstractItem::editActionSlot()
{
    initializeItemDialog();
}

void AbstractItem::downZValueActionSlot()
{
    setZValue(zValue() - 0.1);
}

void AbstractItem::upZValueActionSlot()
{
    setZValue(zValue() + 0.1);
}

void AbstractItem::resizeItem(const QPointF &pointToResize) // додумать учет всех направлений
{
    if(pos().x() < pointToResize.x() && pos().y() < pointToResize.y())
    {
        mItemRectF.setBottomRight(QPointF(fabs(pos().x() - pointToResize.x()),
                                          fabs(pos().x() - pointToResize.x())
                                          * mItemRectF.height()
                                          / mItemRectF.width()));
    }
//    else if(pos().x() > pointToResize.x() && pos().y() > pointToResize.y())
//    {
//        setPos(pointToResize);
//        itemRectF.setT
//    }
    setPolygon(mItemRectF);
    paintItemMembers();
}

void AbstractItem::paintResizePoints(QPainter *painter)
{
    if(isSelected())
    {
        painter->save();
        painter->setRenderHint(QPainter::Antialiasing, false);
        painter->setPen(QPen(Qt::blue));
        painter->setBrush(QBrush(Qt::blue));
        QPainterPath selectPath;
        selectPath.moveTo(mItemRectF.width() - 4, mItemRectF.height() - 4);
        selectPath.lineTo(mItemRectF.width(), mItemRectF.height() - 4);
        selectPath.lineTo(mItemRectF.width(), mItemRectF.height());
        selectPath.lineTo(mItemRectF.width() - 4, mItemRectF.height());
        selectPath.lineTo(mItemRectF.width() - 4, mItemRectF.height() - 4);
        painter->drawPath(selectPath);
        painter->restore();
    }
}

void AbstractItem::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
    if(isSelected() && (event->pos().x() < mItemRectF.width())
            && (event->pos().x() > mItemRectF.width() - 4)
            && (event->pos().y() < mItemRectF.height())
            && (event->pos().y() > mItemRectF.height() - 4))
    {
        setCursor(Qt::SizeFDiagCursor);
        mResizeFlag = true;
    }
//    else if(isSelected())
//    {
//        setCursor(Qt::SizeAllCursor);
//        resizeFlag = false;
//    }
    else
    {
        setCursor(Qt::ArrowCursor);
        mResizeFlag = false;
    }
    QGraphicsPolygonItem::hoverMoveEvent(event);
}

void AbstractItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(mResizeFlag)
        resizeItem(event->scenePos());
    else
        QGraphicsPolygonItem::mouseMoveEvent(event);
}
