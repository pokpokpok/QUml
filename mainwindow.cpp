#include "mainwindow.h"

#include <QtCore/QDebug>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    mTabBar = new QTabWidget();
    mTabBar->setUsesScrollButtons(true);
    mTabBar->setTabsClosable(true);
    mTabBar->setMovable(true);
    setCentralWidget(mTabBar);

    loadActions();
    loadMenu();
    loadStatBar();

    resize(650, 500);
    createNewDiagram(USECASE); // потом переделать с учетом выбора из списка
}

MainWindow::~MainWindow()
{

}

void MainWindow::loadActions()
{
    mNewAction = new QAction(tr("&New"), this);
    mNewAction->setShortcut(QKeySequence::New);
//    newAction->setIcon(QPixmap(":/file-menu/icons/file/new.png"));
    mNewAction->setStatusTip(tr("Create new diagram"));
//    connect(newAction, SIGNAL(triggered()), this, SLOT(createNew()));
    mExitAction = new QAction(tr("E&xit"), this);
    mExitAction->setShortcut(tr("Ctrl+Q"));
//    exitAction->setIcon(QPixmap(":/file-menu/icons/file/exit.png"));
    mExitAction->setStatusTip(tr("Exit the application"));
    connect(mExitAction, SIGNAL(triggered()), this, SLOT(close()));
    mOpenAction = new QAction(tr("&Open..."), this);
    mOpenAction->setShortcut(QKeySequence::Open);
//    openAction->setIcon(QPixmap(":/file-menu/icons/file/open.png"));
    mOpenAction->setStatusTip(tr("Open an existing diagram"));
    connect(mOpenAction, SIGNAL(triggered()), this, SLOT(openDiagram()));
    mSaveAsAction = new QAction(tr("Save &as..."), this);
    mSaveAsAction->setShortcut(QKeySequence::SaveAs);
//    saveAsAction->setIcon(QPixmap(":/file-menu/icons/file/save-as.png"));
    mSaveAsAction->setStatusTip(tr("Save diagram to disk"));
    connect(mSaveAsAction, SIGNAL(triggered()), this, SLOT(saveAsDiagram()));
    mSaveAction = new QAction(tr("&Save"), this);
    mSaveAction->setShortcut(QKeySequence::Save);
//    saveAction->setIcon(QPixmap(":/file-menu/icons/file/save.png"));
    mSaveAction->setStatusTip(tr("Save diagram to disk"));
//    connect(saveAction, SIGNAL(triggered()), this, SLOT(saveFile()));
    mCloseAction = new QAction(tr("&Close"), this);
    mCloseAction->setShortcut(QKeySequence::Close);
//    closeAction->setIcon(QPixmap(":/file-menu/icons/file/close.png"));
    mCloseAction->setStatusTip(tr("Close diagram"));
//    connect(closeAction, SIGNAL(triggered()), this, SLOT(sendToCloseFile()));
    mPrintAction = new QAction(tr("&Print"), this);
    mPrintAction->setShortcut(QKeySequence::Print);
//    printAction->setIcon(QPixmap(":/file-menu/icons/file/print.png"));
    mPrintAction->setStatusTip(tr("Print diagram"));
//    connect(printAction, SIGNAL(triggered()), this, SLOT(printImage()));
    mAboutAction = new QAction(tr("&About"), this);
    mAboutAction->setShortcut(QKeySequence::HelpContents);
//    aboutAction->setIcon(QPixmap(":/about-menu/icons/about/about.png"));
    mAboutAction->setStatusTip(tr("Show the application's About box"));
//    connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));
    mAboutQtAction = new QAction(tr("About &Qt"), this);
    mAboutQtAction->setIcon(QPixmap(":/about-menu/icons/about/aboutQt.png"));
    mAboutQtAction->setStatusTip(tr("Show the Qt library's About box"));
    connect(mAboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
    mUndoAction = new QAction(tr("&Undo"), this);
    mUndoAction->setShortcut(QKeySequence::Undo);
//    undoAction->setIcon(QPixmap(":/edit-menu/icons/edit/undo.png"));
    mUndoAction->setStatusTip(tr("Undo last action"));
//    connect(undoAction, SIGNAL(triggered()), this, SLOT(setUndo()));
    mRedoAction = new QAction(tr("&Redo"), this);
    mRedoAction->setShortcut(QKeySequence::Redo);
//    redoAction->setIcon(QPixmap(":/edit-menu/icons/edit/redo.png"));
    mRedoAction->setStatusTip(tr("Redo action"));
//    connect(redoAction, SIGNAL(triggered()), this, SLOT(setRedo()));
    mCutAction = new QAction(tr("Cut"), this);
    mCutAction->setStatusTip(tr("Cut"));
    mCutAction->setShortcut(QKeySequence::Cut);
//    cutAction->setIcon(QPixmap(":/edit-menu/icons/edit/cut.png"));
//    connect(cutAction, SIGNAL(triggered()), this, SLOT(cutImage()));
    mCopyAction = new QAction(tr("Copy"), this);
    mCopyAction->setStatusTip(tr("Copy"));
    mCopyAction->setShortcut(QKeySequence::Copy);
//    copyAction->setIcon(QPixmap(":/edit-menu/icons/edit/copy.png"));
//    connect(copyAction, SIGNAL(triggered()), this, SLOT(copyImage()));
    mPasteAction = new QAction(tr("Paste"), this);
    mPasteAction->setStatusTip(tr("Paste"));
    mPasteAction->setShortcut(QKeySequence::Paste);
//    pasteAction->setIcon(QPixmap(":/edit-menu/icons/edit/paste.png"));
//    connect(pasteAction, SIGNAL(triggered()), this, SLOT(pasteImage()));
}

/*!
 \brief загрузка меню

*/
void MainWindow::loadMenu()
{
    mFileMenu = menuBar()->addMenu(tr("&File"));
    mFileMenu->addAction(mNewAction);
    mFileMenu->addAction(mOpenAction);
    mFileMenu->addAction(mSaveAction);
    mFileMenu->addAction(mSaveAsAction);
    mFileMenu->addAction(mCloseAction);
    mFileMenu->addSeparator();
    mFileMenu->addAction(mPrintAction);
    mFileMenu->addSeparator();
    mFileMenu->addAction(mExitAction);
    mEditMenu = menuBar()->addMenu(tr("&Edit"));
    mEditMenu->addAction(mUndoAction);
    mEditMenu->addAction(mRedoAction);
    mEditMenu->addSeparator();
    mEditMenu->addAction(mCopyAction);
    mEditMenu->addAction(mPasteAction);
    mEditMenu->addAction(mCutAction);
    mAboutMenu = menuBar()->addMenu(tr("&About"));
    mAboutMenu->addAction(mAboutAction);
    mAboutMenu->addAction(mAboutQtAction);
}

/*!
 \brief загрузка статус-бара

*/
void MainWindow::loadStatBar()
{
    mStatBar = new QStatusBar();
    setStatusBar(mStatBar);
}

void MainWindow::createNewDiagram(DiagramsEnum type)
{
    switch(type)
    {
    case ABSTRACT:
        break;
    case USECASE:
        DiagramViewer *newView = new DiagramViewer(type, this);
        mTabBar->addTab(newView, tr("new use case"));
        mTabBar->setCurrentIndex(mTabBar->count()-1);
        mUseCaseToolBar = new UseCaseToolBar(tr("&Items"), this);
        this->addToolBar(Qt::LeftToolBarArea, mUseCaseToolBar);
        connect(mUseCaseToolBar, SIGNAL(sendSceneState(QString)), newView, SLOT(setSceneState(QString)));
        break;
    }
}

void MainWindow::saveAsDiagram()
{
    QFileDialog::Options options;
    QString filter;
    options |= QFileDialog::DontUseNativeDialog;
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                    "",
                                                    tr("*.quml"),
                                                    &filter,
                                                    options);
    if(!fileName.isEmpty())
    {
        QApplication::setOverrideCursor(Qt::WaitCursor);
        int length(filter.size());
        for(int i(length - 1); i > 0; i--)
        {
            if(filter[i] != fileName[fileName.size() - length + i])
            {
                fileName += filter.mid(1);
                break;
            }
        }
        DiagramViewer *tempDiag = qobject_cast<DiagramViewer*>(mTabBar->currentWidget());
        tempDiag->saveDiagramSceneToFile(fileName);
//        fileName = tempView->setFilePath(fileName);
//        tabBar->setTabText(tabBar->currentIndex(), fileName);
        mStatBar->showMessage(tr("Save completed"), 2000);
        QApplication::restoreOverrideCursor();
    }
}

void MainWindow::openDiagram()
{
    QFileDialog::Options options;
    QString filter;
    options |= QFileDialog::DontUseNativeDialog;
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"",
                                                    tr("All supported (*.quml);; All (*.*)"),
                                                    &filter,
                                                    options);

    if(!fileName.isEmpty())
    {
        DiagramViewer *tempDiag = qobject_cast<DiagramViewer*>(mTabBar->currentWidget());
        tempDiag->openDiagramSceneFromFile(fileName); //перепилить с учетом табов
    }
}
