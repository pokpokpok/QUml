#ifndef RELATIONEVENTHANDLER_H
#define RELATIONEVENTHANDLER_H

#include "event_handler/abstracteventhandler.h"

class RelationEventHandler : public AbstractEventHandler
{
    Q_OBJECT

public:
    explicit RelationEventHandler(DiagramScene *parent = 0);
    ~RelationEventHandler();

public slots:
    void mouseDoubleClick(QGraphicsSceneMouseEvent *event);
    void mousePress(QGraphicsSceneMouseEvent *event);
    void mouseMove(QGraphicsSceneMouseEvent *event);
    void mouseRelease(QGraphicsSceneMouseEvent *event);

signals:

};

#endif // RELATIONEVENTHANDLER_H
