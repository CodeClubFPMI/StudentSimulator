#include "mainmenu.h"

MainMenu::MainMenu(QWidget *parent) : QWidget(parent), layout_(this), but_new_game_(this), but_load_game_(this),
    but_statisic_(this), but_settings_(this), but_exit_(this)
{
    but_new_game_.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    but_load_game_.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    but_statisic_.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    but_settings_.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    but_exit_.setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    //but_new_game_.setFixedSize(200, 50);
    layout_.addWidget(&but_new_game_, 1);
    layout_.addWidget(&but_load_game_, 2);
    layout_.addWidget(&but_statisic_, 3);
    layout_.addWidget(&but_settings_, 4);
    layout_.addWidget(&but_exit_, 5);
}
