#include "utilities.h"
#include "button.h"
#include "JSONparser.h"

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
