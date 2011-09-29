#include "diagramviewer.h"

#include <QtGui/QScrollBar>
#include <QtCore/QDebug>

DiagramViewer::DiagramViewer(const DiagramsEnum &diagramType, QWidget *parent) :
    QGraphicsView(parent)
{
//    setSceneRect(0, 0, 1000, 1000);
    setDragMode(QGraphicsView::RubberBandDrag);
    setRubberBandSelectionMode(Qt::IntersectsItemBoundingRect);
//    setCacheMode(CacheNone);//CacheBackground);
//    setViewportUpdateMode(BoundingRectViewportUpdate);
//    setTransformationAnchor(AnchorUnderMouse);
//    setResizeAnchor(AnchorViewCenter);
//    setOptimizationFlag(DontAdjustForAntialiasing);
//    setAcceptDrops(true);

//    verticalScrollBar()->setSliderPosition(500);
//    horizontalScrollBar()->setSliderPosition(500);

    initializeDiagramScene(diagramType, parent);
}

void DiagramViewer::initializeDiagramScene(const DiagramsEnum &diagramType, QObject *parent)
{
    mDiagScene = new DiagramScene(parent);
    mDiagScene->setDiagType(diagramType);
    setScene(mDiagScene);
}

void DiagramViewer::setSceneState(const QString &state)
{
    mDiagScene->setSceneState(state);
}

void DiagramViewer::saveDiagramSceneToFile(const QString &fileName)
{
    mDiagScene->saveSceneToFile(fileName);
}

void DiagramViewer::openDiagramSceneFromFile(const QString &fileName)
{
    mDiagScene->openSceneFromFile(fileName);
}
