#include "moneymenu.h"
#include "Utilities/utilities.h"

MoneyMenu::MoneyMenu(QWidget *parent) : QWidget(parent)
{
    // TODO scrollBar (or Area, I don't know)

    menu_buttons::make_buttons("money_buttons.json", buttons_, layout_);
    mapper_ = new QSignalMapper;

    for (int i = 0; i < buttons_.size(); ++i) {
        connect(buttons_[i]->get_button_ptr(), SIGNAL(clicked()), mapper_, SLOT(map()));
        mapper_->setMapping(buttons_[i]->get_button_ptr(), i);
    }
    connect(mapper_, SIGNAL(mappedInt(int)), this, SIGNAL(SendButtonId(int)));
    setLayout(&layout_);
}
