#include "abstract_diagram/abstractitemdialog.h"

#include <QtGui/QPushButton>

AbstractItemDialog::AbstractItemDialog(QWidget *parent) :
    QDialog(parent)
{
    mButtonAccept = new QPushButton(tr("Accept"));
    mButtonAccept->setDefault(true);
    connect(mButtonAccept, SIGNAL(clicked()), this, SLOT(buttonAcceptSlot()));

    mButtonCancel = new QPushButton(tr("Cancel"));
    connect(mButtonCancel, SIGNAL(clicked()), this, SLOT(reject()));
}
