#include "event_handler/abstracteventhandler.h"

AbstractEventHandler::AbstractEventHandler(DiagramScene *parent) :
    QObject(parent), mDiagScene(parent)
{

}
