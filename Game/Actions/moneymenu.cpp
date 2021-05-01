#include "moneymenu.h"
#include "Utilities/utilities.h"

MoneyMenu::MoneyMenu(QWidget *parent) : QWidget(parent)
{
    // TODO scrollBar (or Area, I don't know)

    menu_buttons::make_buttons("money_buttons.json", buttons_, layout_);
    setLayout(&layout_);
}
