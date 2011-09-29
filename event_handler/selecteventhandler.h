#ifndef SELECTEVENTHANDLER_H
#define SELECTEVENTHANDLER_H

#include "event_handler/abstracteventhandler.h"

class SelectEventHandler : public AbstractEventHandler
{
    Q_OBJECT
public:
    explicit SelectEventHandler(DiagramScene *parent = 0);
    ~SelectEventHandler();

public slots:
    void mouseDoubleClick(QGraphicsSceneMouseEvent *event);
    void mousePress(QGraphicsSceneMouseEvent *event);
    void mouseMove(QGraphicsSceneMouseEvent *event);
    void mouseRelease(QGraphicsSceneMouseEvent *event);

signals:

};

#endif // SELECTEVENTHANDLER_H
