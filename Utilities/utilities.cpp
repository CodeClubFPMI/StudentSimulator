#include "utilities.h"
#include "button.h"
#include <QVBoxLayout>

void menu_buttons::add_buttons(QVector<Button *> &buttons, QVBoxLayout &layout_){
    for (int i = 0; i < buttons.size(); ++i){
        layout_.addWidget(buttons[i]->get_button_ptr(), 1);
    }
}
