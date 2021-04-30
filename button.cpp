#include "button.h"

Button::Button(QWidget *parent) : QWidget(parent){}

// getters

int Button::get_food_changes(){
    return food_;
}
int Button::get_happiness_changes(){
    return happiness_;
}
int Button::get_education_changes(){
    return education_;
}
int Button::get_health_changes(){
    return health_;
}
int Button::get_energy_changes(){
    return energy_;
}
qreal Button::get_money_changes(){
    return money_;
}
QPushButton * Button::get_button_ptr(){
    return button_;
}
