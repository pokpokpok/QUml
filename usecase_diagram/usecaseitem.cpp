#include "usecase_diagram/usecaseitem.h"

#include <QtGui/QBrush>
#include <QtGui/QPen>
#include <QtCore/QDebug>
#include <QtGui/QPainter>
#include <QtGui/QPainterPath>
#include <QtGui/QGraphicsScene>

UseCaseItem::UseCaseItem(int newItemId, const QString &newItemType,
                     const QString &newItemName, const QPointF &newItemPos,
                     QGraphicsItem *parent, QGraphicsScene *scene) :
    AbstractItem(newItemId, newItemType, newItemName, newItemPos, parent, scene)
{
    initializeItemMembers();
//    scene()->removeItem(this);
}

UseCaseItem::~UseCaseItem()
{

}

void UseCaseItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QGraphicsPolygonItem::paint(painter, option, widget);
    painter->setBrush(QBrush(Qt::white));

    if(mItemType == "I_ACTOR")
    {
        painter->setPen(QPen(Qt::black/*, 1.5*/));

        QPainterPath linePath;
        linePath.moveTo(mItemRectF.width() / 2, mItemRectF.height() / 6 * 2);
        linePath.lineTo(mItemRectF.width() / 2, mItemRectF.height() / 12 * 9);
        linePath.moveTo(mItemRectF.width() / 8, mItemRectF.height() / 6 * 3);
        linePath.lineTo(mItemRectF.width() / 8 * 7, mItemRectF.height() / 6 * 3);
        painter->drawPath(linePath);

        painter->setRenderHint(QPainter::Antialiasing, true);

        QPainterPath cornerPath;
        cornerPath.moveTo(mItemRectF.width() / 2, mItemRectF.height() / 12 * 9);
        cornerPath.lineTo(mItemRectF.width() / 4, mItemRectF.height());
        cornerPath.moveTo(mItemRectF.width() / 2, mItemRectF.height() / 12 * 9);
        cornerPath.lineTo(mItemRectF.width() / 4 * 3, mItemRectF.height());
        painter->drawPath(cornerPath);

        painter->drawEllipse(QPointF(mItemRectF.width() / 2, mItemRectF.height() / 6),
                             mItemRectF.width() / 4, mItemRectF.width() / 4);
    }
    else if(mItemType == "I_USECASE")
    {
        painter->setPen(QPen(Qt::black));
        painter->setRenderHint(QPainter::Antialiasing, true);
        painter->drawEllipse(mItemRectF);
    }

   paintResizePoints(painter);
}

void UseCaseItem::initializeItemMembers()
{
    if(mItemType == "I_ACTOR")
    {
        mItemRectF = QRectF(0, 0, 50, 75);
        setPen(Qt::NoPen);

        if(mItemName.isEmpty())
            mItemName = "Actor";
    }
    else if(mItemType == "I_USECASE")
    {
        setPen(Qt::NoPen);

        if(mItemName.isEmpty())
            mItemName = "Use case";
    }

    setPolygon(QPolygonF(mItemRectF));
    mTextNameItem = new QGraphicsTextItem(mItemName, this);
    paintItemMembers();
}

void UseCaseItem::paintItemMembers()
{
    mTextNameItem->setPlainText(mItemName);
    if(mItemType == "I_ACTOR")
        mTextNameItem->setPos((mItemRectF.width() - mTextNameItem->boundingRect().width())/2,
                              - mTextNameItem->boundingRect().height());
    else
        mTextNameItem->setPos((mItemRectF.width() - mTextNameItem->boundingRect().width())/2,
                              (mItemRectF.height() - mTextNameItem->boundingRect().height())/2);
}

void UseCaseItem::initializeItemDialog()
{
    UseCaseItemDialog *itemDialog = new UseCaseItemDialog(getItemName());
    connect(itemDialog, SIGNAL(sendNewItemName(QString)), this, SLOT(setItemName(QString)));
    itemDialog->show();
    itemDialog->raise();
    itemDialog->activateWindow();
}
