#ifndef BLOCKTOOLBAR_H
#define BLOCKTOOLBAR_H

#include "abstract_diagram/abstracttoolbar.h"

QT_BEGIN_NAMESPACE
class QToolButton;
QT_END_NAMESPACE

class UseCaseToolBar : public AbstractToolBar
{
    Q_OBJECT

public:
    explicit UseCaseToolBar(const QString &title, QWidget *parent = 0);
    ~UseCaseToolBar();

private:
    void initializeBarElements();

    QToolButton *mActorButton, *mUseCaseButton;

signals:

private slots:
    void sendActorButtonState(bool);
    void sendUseCaseButtonState(bool);

};

#endif // BLOCKTOOLBAR_H
