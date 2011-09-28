#ifndef BLOCKITEMDIALOG_H
#define BLOCKITEMDIALOG_H

#include "abstract_diagram/abstractitemdialog.h"

QT_BEGIN_NAMESPACE
class QTextEdit;
QT_END_NAMESPACE

class UseCaseItemDialog : public AbstractItemDialog
{
    Q_OBJECT

public:
    explicit UseCaseItemDialog(const QString &currentItemName, QWidget *parent = 0);
    ~UseCaseItemDialog();

private:
    QTextEdit *mItemNameEdit;

private slots:
    void buttonAcceptSlot();

};

#endif // BLOCKITEMDIALOG_H
