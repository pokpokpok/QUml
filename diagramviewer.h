#ifndef DIAGRAMVIEWER_H
#define DIAGRAMVIEWER_H

#include "diagramscene.h"
#include "qumlenums.h"

#include <QtGui/QGraphicsView>

class DiagramViewer : public QGraphicsView
{
    Q_OBJECT

public:
    explicit DiagramViewer(const DiagramsEnum &diagramType, QWidget *parent = 0);

private:
    void initializeDiagramScene(const DiagramsEnum &diagramType, QObject *parent);

    DiagramScene *mDiagScene;

signals:

public slots:
    void setSceneState(const QString &state);
    void saveDiagramSceneToFile(const QString &fileName);
    void openDiagramSceneFromFile(const QString &fileName);

protected:

};

#endif // DIAGRAMVIEWER_H
