#include "Game/Actions/foodmenu.h"
#include "Utilities/utilities.h"

#include <QWidget>
#include <QPushButton>
#include <QVector>

FoodMenu::FoodMenu(QWidget *parent) : QWidget(parent)
{
    // TODO scrollBar (or Area, I don't know)

    menu_buttons::make_buttons("food_buttons.json", buttons_, layout_);

    setLayout(&layout_);
}
