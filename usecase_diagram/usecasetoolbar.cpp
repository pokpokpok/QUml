#include "usecase_diagram/usecasetoolbar.h"

#include <QtGui/QGridLayout>
#include <QtGui/QToolButton>

UseCaseToolBar::UseCaseToolBar(const QString &title, QWidget *parent) :
    AbstractToolBar(title, parent)
{
    initializeBarElements();
}

UseCaseToolBar::~UseCaseToolBar()
{

}

void UseCaseToolBar::initializeBarElements()
{
    mActorButton = new QToolButton();
    mActorButton->setMinimumSize(mBaseIconSize);
    mActorButton->setMaximumSize(mBaseIconSize);
    mActorButton->setText(tr("A"));
//    startBlockButton->setIcon();
    mActorButton->setStatusTip(tr("Add actor"));
    mActorButton->setCheckable(true);
    connect(mActorButton, SIGNAL(toggled(bool)), this, SLOT(sendActorButtonState(bool)));
    mUseCaseButton = new QToolButton();
    mUseCaseButton->setMinimumSize(mBaseIconSize);
    mUseCaseButton->setMaximumSize(mBaseIconSize);
    mUseCaseButton->setText(tr("U"));
//    computationBlockButton->setIcon();
    mUseCaseButton->setStatusTip(tr("Add use case"));
    mUseCaseButton->setCheckable(true);
    connect(mUseCaseButton, SIGNAL(toggled(bool)), this, SLOT(sendUseCaseButtonState(bool)));

    QGridLayout *gLayout = new QGridLayout();
    gLayout->setMargin(3);
    gLayout->addWidget(mActorButton, 0, 0);
    gLayout->addWidget(mUseCaseButton, 0, 1);

    QWidget *gWidget = new QWidget();
    gWidget->setLayout(gLayout);

    addWidget(gWidget);
}

void UseCaseToolBar::sendActorButtonState(bool flag)
{
    if(flag)
    {
        mActorButton->setChecked(true);
        mUseCaseButton->setChecked(false);
        emit sendSceneState("I_ACTOR");
    }
    else
    {
        mActorButton->setChecked(false);
        emit sendSceneState("S_NONE");
    }
}

void UseCaseToolBar::sendUseCaseButtonState(bool flag)
{
    if(flag)
    {
        mActorButton->setChecked(false);
        mUseCaseButton->setChecked(true);
        emit sendSceneState("I_USECASE");
    }
    else
    {
        mUseCaseButton->setChecked(false);
        emit sendSceneState("S_NONE");
    }
}
