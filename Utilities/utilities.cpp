#include "utilities.h"
#include "button.h"
#include "JSONparser.h"
#include "Game/parametrs.h"
#include <QFile>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QVBoxLayout>

const int kDaysInSemestr = 120;

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

void menu_buttons::make_buttons_enable(QVector<Button *> &buttons, Student * student){
    for (int i = 0; i < buttons.size(); ++i){
        if(buttons[i]->get_available_sem() > student->get_sem_value()){
            buttons[i]->get_button_ptr()->setEnabled(false);
        }
        else{
            buttons[i]->get_button_ptr()->setEnabled(true);
        }
    }
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

void data_update::make_statistic(Student * student){
    JSONParser parser;
    QVector<QPair<int, QString>> statistic = parser.statistic_from_json();
    statistic.push_back(QPair<int, QString>((student->get_sem_value() - 1)*kDaysInSemestr + student->get_day(),
                                            student->get_name()));
    parser.statistic_to_json(statistic);
}
