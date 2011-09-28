#ifndef USCASEITEM_H
#define USCASEITEM_H

#include "abstract_diagram/abstractitem.h"
#include "usecase_diagram/usecaseitemdialog.h"

class UseCaseItem : public AbstractItem
{
public:
    explicit UseCaseItem(int newItemId, const QString &newItemType,
                       const QString &newItemName, const QPointF &newItemPos,
                       QGraphicsItem *parent = 0, QGraphicsScene *scene = 0);
    ~UseCaseItem();

    void setAttributesList(const QList<QString> &newAttrList){}
    void setMethodsList(const QList<QString> &newMethList){}

private:
    QGraphicsTextItem *mTextNameItem;

protected:
    void initializeItemDialog();
    void initializeItemMembers();
    void paintItemMembers();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:

public slots:

};

#endif // USCASEITEM_H
