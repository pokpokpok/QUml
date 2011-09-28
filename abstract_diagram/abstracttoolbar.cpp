#include "abstract_diagram/abstracttoolbar.h"

AbstractToolBar::AbstractToolBar(const QString &title, QWidget *parent) :
    QToolBar(title, parent), mBaseIconSize(35, 35)
{
    setMovable(false);
}
