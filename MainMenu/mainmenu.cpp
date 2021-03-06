#include "mainmenu.h"
#include <QPushButton>

MainMenu::MainMenu(QWidget *parent) : QWidget(parent), layout_(this)
{
    // adding menu buttons
    QPushButton * but_new_game_ = new QPushButton("New Game", this);
    QPushButton * but_load_game_ = new QPushButton("Load Game", this);
    QPushButton * but_statistic_ = new QPushButton("Statistic", this);
    QPushButton * but_settings_ = new QPushButton("Settings", this);
    QPushButton * but_exit_ = new QPushButton("Exit", this);

    but_new_game_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    but_load_game_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    but_statistic_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    but_settings_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    but_exit_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    layout_.addWidget(but_new_game_, 1);
    layout_.addWidget(but_load_game_, 1);
    layout_.addWidget(but_statistic_, 1);
    layout_.addWidget(but_settings_, 1);
    layout_.addWidget(but_exit_, 1);

    layout_.setSpacing(40);
    layout_.setContentsMargins(250, 200, 250, 200);
    setLayout(&layout_);

    //send signals from menu to main window
    connect(but_exit_, &QPushButton::clicked, this, &MainMenu::GoToExit);
    connect(but_new_game_, &QPushButton::clicked, this, &MainMenu::GoToNewGame);
    connect(but_settings_, &QPushButton::clicked, this, &MainMenu::GoToSettings);
    connect(but_statistic_, &QPushButton::clicked, this, &MainMenu::GoToStatistic);
    connect(but_load_game_, &QPushButton::clicked, this, &MainMenu::GoToLoadGame);


}
