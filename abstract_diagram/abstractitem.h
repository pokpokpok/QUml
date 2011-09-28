#ifndef ABSTRACTITEM_H
#define ABSTRACTITEM_H

#include <QtGui/QGraphicsPolygonItem>
#include <QtCore/QObject>

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
QT_END_NAMESPACE

class AbstractItem : public QObject, public QGraphicsPolygonItem
{
    Q_OBJECT

public:
    AbstractItem(int newItemId, const QString &newItemType,
                 const QString &newItemName, const QPointF &newItemPos,
                 QGraphicsItem *parent = 0, QGraphicsScene *scene = 0);
    virtual ~AbstractItem(){}

    inline QString getItemName(){ return mItemName; }
    inline QString getItemType(){ return mItemType; }
    inline QList<QString> getItemAttributesList(){ return mItemAttributes; }
    inline QList<QString> getItemMethodsList(){ return mItemMethods; }
    inline int getItemId(){ return mItemId; }
    void resizeItem(const QPointF &pointToResize);

    virtual void setAttributesList(const QList<QString> &newAttrList)=0; //возможно поменяется логика
    virtual void setMethodsList(const QList<QString> &newMethList)=0; //возможно поменяется логика

private:
    void initializeContextMenu();

    bool mResizeFlag;

protected:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void paintResizePoints(QPainter *painter);

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)=0;
    virtual void initializeItemMembers()=0;
    virtual void paintItemMembers()=0;
    virtual void initializeItemDialog()=0;

    QRectF mItemRectF;
    QString mItemName, mItemType;
    QList<QString> mItemAttributes, mItemMethods;
    QAction *mEditAction, *mDeleteAction, *mDownZValueAction, *mUpZValueAction;
    QMenu *mItemMenu;
    int mItemId;

public slots:
    void setItemName(const QString &newItemName);

private slots:
    void deleteActionSlot();
    void editActionSlot();
    void downZValueActionSlot();
    void upZValueActionSlot();

signals:
    void sendIdToDel(int);

};

#endif // ABSTRACTITEM_H
