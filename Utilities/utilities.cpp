#include "utilities.h"
#include "button.h"
#include "JSONparser.h"
#include "Game/parametrs.h"

#include <QVBoxLayout>

void menu_buttons::make_buttons(const QString &file_name, QVector<Button *> &buttons, QVBoxLayout &layout){
    JSONParser parser;
    buttons = parser.buttons_form_json(file_name);
    menu_buttons::add_buttons(buttons, layout);
    menu_buttons::change_buttons_style(buttons, layout);
}

void menu_buttons::add_buttons(QVector<Button *> &buttons, QVBoxLayout &layout_){
    for (int i = 0; i < buttons.size(); ++i){
        layout_.addWidget(buttons[i]->get_button_ptr(), 1);
    }
}

void menu_buttons::change_buttons_style(QVector<Button *> &buttons, QVBoxLayout &layout){
    for (int i = 0; i < buttons.size(); ++i){
        buttons[i]->get_button_ptr()->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    }
    layout.setSpacing(5);
    layout.setContentsMargins(100, 100, 100, 100);
}

void data_update::refresh_parameters_on_window(QWidget * widget, Student * student){
    dynamic_cast<Parametrs *>(widget)->setFoodCurrentValue(student->get_food_value());
    dynamic_cast<Parametrs *>(widget)->setHealthCurrentValue(student->get_health_value());
    dynamic_cast<Parametrs *>(widget)->setHappinessCurrentValue(student->get_happiness_value());
    dynamic_cast<Parametrs *>(widget)->setMoneyCurrentValue(student->get_money_value());
    dynamic_cast<Parametrs *>(widget)->setEnergyCurrentValue(student->get_energy_value());
    dynamic_cast<Parametrs *>(widget)->setEducationCurrentValue(student->get_education_value());
    dynamic_cast<Parametrs *>(widget)->setTimeCurrentValue(student->get_time());
    dynamic_cast<Parametrs *>(widget)->setSemestrCurrentValue(student->get_sem_value());
    dynamic_cast<Parametrs *>(widget)->setDayCurrentValue(student->get_day());
}
