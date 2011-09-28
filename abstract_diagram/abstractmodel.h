#ifndef ABSTRACTMODEL_H
#define ABSTRACTMODEL_H

#include "abstract_diagram/abstractitem.h"

#include <QtCore/QObject>

class AbstractModel : public QObject
{
    Q_OBJECT

public:
    explicit AbstractModel(QObject *parent = 0);
    virtual ~AbstractModel(){}

    virtual void saveModel(const QString &fileName, const QList<AbstractItem*> itemsList/*,
                           const QList<AbstractRelation*> relationList*/)=0;
    virtual void loadModel(const QString &fileName)=0;

signals:
    void addNewItem(const QString &newItemType, const QString &newItemName, const QPointF &newItemPos);
//    void addRelation();

public slots:

};

#endif // ABSTRACTMODEL_H
