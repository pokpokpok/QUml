#ifndef ABSTRACTTOOLBAR_H
#define ABSTRACTTOOLBAR_H

#include <QtGui/QToolBar>

class AbstractToolBar : public QToolBar
{
    Q_OBJECT

public:
    explicit AbstractToolBar(const QString &title, QWidget *parent = 0);
    virtual ~AbstractToolBar(){}

private:
    virtual void initializeBarElements()=0;

signals:
    void sendItemState(const QString &itemState);

public slots:

protected:
    QSize mBaseIconSize;

};

#endif // ABSTRACTTOOLBAR_H
