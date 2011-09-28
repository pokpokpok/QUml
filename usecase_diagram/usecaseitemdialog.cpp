#include "usecase_diagram/usecaseitemdialog.h"

#include <QtGui/QTextEdit>
#include <QtGui/QHBoxLayout>
#include <QtGui/QVBoxLayout>
#include <QtGui/QPushButton>

UseCaseItemDialog::UseCaseItemDialog(const QString &currentItemName, QWidget *parent) :
    AbstractItemDialog(parent)
{
    setWindowTitle(tr("Edit item"));
    mItemNameEdit = new QTextEdit(currentItemName);

    QHBoxLayout *hBox1 = new QHBoxLayout();
    hBox1->addWidget(mItemNameEdit);
    QHBoxLayout *hBox2 = new QHBoxLayout();
    hBox2->addWidget(mButtonAccept);
    hBox2->addWidget(mButtonCancel);
    QVBoxLayout *vBox = new QVBoxLayout();
    vBox->addLayout(hBox1);
    vBox->addLayout(hBox2);
    setLayout(vBox);
}

UseCaseItemDialog::~UseCaseItemDialog()
{

}

void UseCaseItemDialog::buttonAcceptSlot()
{
    emit sendNewItemName(mItemNameEdit->toPlainText());
    close();
}
