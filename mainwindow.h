#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qumlenums.h"
#include "diagramviewer.h"
#include "usecase_diagram/usecasetoolbar.h"

#include <QtGui/QMainWindow>

QT_BEGIN_NAMESPACE
class QMenu;
class QStatusBar;
class QTabWidget;
class QAction;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void loadMenu();
    void loadActions();
    void loadStatBar();
//    void loadToolBars();
//    void loadSignals();
    void createNewDiagram(DiagramsEnum type);

    QMenu *mFileMenu, *mEditMenu, *mAboutMenu;
    QStatusBar *mStatBar;
    QTabWidget *mTabBar;
    QAction *mNewAction, *mExitAction, *mOpenAction, *mSaveAsAction,
            *mSaveAction, *mCloseAction, *mAboutAction, *mAboutQtAction,
            *mUndoAction, *mRedoAction, *mPrintAction,
            *mCutAction, *mCopyAction, *mPasteAction;
    UseCaseToolBar *mUseCaseToolBar;

protected:
//    void mousePressEvent(QMouseEvent*);
//    void mouseMoveEvent(QMouseEvent*);
//    void mouseReleaseEvent(QMouseEvent*);

private slots:
    void saveAsDiagram();
    void openDiagram();

};

#endif // MAINWINDOW_H
