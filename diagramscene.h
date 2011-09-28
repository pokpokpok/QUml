#ifndef DIAGRAMSCENE_H
#define DIAGRAMSCENE_H

#include "abstract_diagram/abstractitem.h"
#include "usecase_diagram/usecasemodel.h"
#include "usecase_diagram/usecaseitem.h"
#include "qumlenums.h"

#include <QtGui/QGraphicsScene>
#include <QtGui/QGraphicsSceneMouseEvent>

class DiagramScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit DiagramScene(QObject *parent = 0);
    ~DiagramScene();

    inline void setItemState(const QString &newItemState){ mItemState = newItemState; }
    inline void setDiagType(const DiagramsEnum &newDiagType){ mDiagType = newDiagType; }
    inline DiagramsEnum getDiagType() { return mDiagType; }
    void saveSceneToFile(const QString &fileName);
    void openSceneFromFile(const QString &fileName);

private:
    QString mItemState;
    QList<AbstractItem*> mItemsPtrList;
    int mCountItemsId;
    DiagramsEnum mDiagType;

signals:

private slots:
    void deleteItem(int itemIdToDel);
    void addNewItem(const QString &newItemType, const QString &newItemName, const QPointF &newItemPos);
    void addNewRelation(const QString &type);

protected:
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};

#endif // DIAGRAMSCENE_H
