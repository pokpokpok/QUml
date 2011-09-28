#ifndef BLOCKMODEL_H
#define BLOCKMODEL_H

#include "abstract_diagram/abstractmodel.h"

class UseCaseModel : public AbstractModel
{
    Q_OBJECT

public:
    explicit UseCaseModel(QObject *parent = 0);
    ~UseCaseModel();

    void saveModel(const QString &fileName, const QList<AbstractItem*> itemsList);
    void loadModel(const QString &fileName);

signals:

public slots:

};

#endif // BLOCKMODEL_H
