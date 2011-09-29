#ifndef ITEMEVENTHANDLER_H
#define ITEMEVENTHANDLER_H

#include "event_handler/abstracteventhandler.h"

class ItemEventHandler : public AbstractEventHandler
{
    Q_OBJECT
public:
    explicit ItemEventHandler(DiagramScene *parent = 0);
    ~ItemEventHandler();

protected:
    virtual void mouseDoubleClick(QGraphicsSceneMouseEvent *event)=0;
    virtual void mousePress(QGraphicsSceneMouseEvent *event)=0;
    virtual void mouseMove(QGraphicsSceneMouseEvent *event)=0;
    virtual void mouseRelease(QGraphicsSceneMouseEvent *event)=0;

signals:

public slots:

};

#endif // ITEMEVENTHANDLER_H
