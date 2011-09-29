#ifndef DIAGRAMSCENE_H
#define DIAGRAMSCENE_H

#include "abstract_diagram/abstractitem.h"
#include "usecase_diagram/usecasemodel.h"
#include "usecase_diagram/usecaseitem.h"
#include "qumlenums.h"

#include <QtGui/QGraphicsScene>
#include <QtGui/QGraphicsSceneMouseEvent>

QT_BEGIN_NAMESPACE
class AbstractEventHandler;
QT_END_NAMESPACE

class DiagramScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit DiagramScene(QObject *parent = 0);
    ~DiagramScene();

    void setSceneState(const QString &newSceneState);
    inline QString getSceneState() { return mSceneState; }
    inline void setDiagType(const DiagramsEnum &newDiagType){ mDiagType = newDiagType; }
    inline DiagramsEnum getDiagType() { return mDiagType; }
    void saveSceneToFile(const QString &fileName);
    void openSceneFromFile(const QString &fileName);

private:
    QString mSceneState;
    DiagramsEnum mDiagType;
    QList<AbstractItem*> mItemsPtrList;
    int mCountItemsId;
    QVector<AbstractEventHandler*> mSceneEventHandlers;
    AbstractEventHandler *mEventHandler;

signals:

public slots:
    void addNewItem(const QString &newItemType, const QString &newItemName, const QPointF &newItemPos);
    void addNewRelation(const QString &type);

private slots:
    void deleteItem(int itemIdToDel);

protected:
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};

#endif // DIAGRAMSCENE_H
