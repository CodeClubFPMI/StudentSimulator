#include "foodmenu.h"
#include "student.h"
#include "JSONparser.h"
#include "utilities.h"

#include <QWidget>
#include <QPushButton>
#include <QVector>

FoodMenu::FoodMenu(QWidget *parent) : QWidget(parent)
{
    // TODO scrollBar (or Area, I don't know)

    JSONParser parser;
    buttons_ = parser.buttons_form_json("food_buttons.json");
    menu_buttons::add_buttons(buttons_, layout_);

    // buttons_[i]->get_button_ptr()->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout_.setSpacing(5);
    layout_.setContentsMargins(100, 100, 100, 100);

    setLayout(&layout_);
}
