#ifndef ABSTRACTEVENTHANDLER_H
#define ABSTRACTEVENTHANDLER_H

#include <QtCore/QObject>
#include <QtGui/QMouseEvent>

#include "diagramscene.h"

class AbstractEventHandler : public QObject
{
    Q_OBJECT

public:
    explicit AbstractEventHandler(DiagramScene *parent);
    virtual ~AbstractEventHandler(){}

public slots:
    virtual void mouseDoubleClick(QGraphicsSceneMouseEvent *event)=0;
    virtual void mousePress(QGraphicsSceneMouseEvent *event)=0;
    virtual void mouseMove(QGraphicsSceneMouseEvent *event)=0;
    virtual void mouseRelease(QGraphicsSceneMouseEvent *event)=0;

protected:
    DiagramScene *mDiagScene;

signals:

};

#endif // ABSTRACTEVENTHANDLER_H
