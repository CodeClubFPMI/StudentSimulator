#include "happinessmenu.h"
#include "Utilities/utilities.h"

#include <QWidget>
#include <QPushButton>
#include <QVector>

HappinessMenu::HappinessMenu(QWidget *parent) : QWidget(parent)
{
    // TODO scrollBar (or Area, I don't know)

    menu_buttons::make_buttons("happiness_buttons.json", buttons_, layout_);
    setLayout(&layout_);
}
