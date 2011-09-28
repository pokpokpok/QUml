#ifndef ABSTRACTITEMDIALOG_H
#define ABSTRACTITEMDIALOG_H

#include <QtGui/QDialog>

QT_BEGIN_NAMESPACE
class QPushButton;
QT_END_NAMESPACE

class AbstractItemDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AbstractItemDialog(QWidget *parent = 0);
    virtual ~AbstractItemDialog(){}

protected:
    QPushButton *mButtonAccept, *mButtonCancel;

signals:
    void sendNewItemName(const QString&);
    void sendNewItemAttributesList(const QList<QString>&);
    //добавить потом остальное

private slots:
    virtual void buttonAcceptSlot()=0;

};

#endif // ABSTRACTITEMDIALOG_H
