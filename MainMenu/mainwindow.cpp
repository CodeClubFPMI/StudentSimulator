#include "mainwindow.h"
#include "settings.h"

#include <QFile>
#include "Game/foodmenu.h"
#include "Game/Actions/energymenu.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent), stacked_widget_(this)

{
    main_menu_ = new MainMenu;
    game_window_ = new GameWindow;
    settings_ = new Settings;
    statistic_ = new Statistic;

    resize(800, 1000);

    stacked_widget_.addWidget(main_menu_);
    stacked_widget_.addWidget(game_window_);
    stacked_widget_.addWidget(statistic_);
    stacked_widget_.addWidget(settings_);
    stacked_widget_.show();
    setLayout(stacked_widget_.layout());


    //Upload css to game window
    QFile file(":/Styles/GameMenuStyles.css");
    file.open(QFile::ReadOnly);
    game_window_->setStyleSheet(file.readAll());

    //closing game
    connect(main_menu_, &MainMenu::GoToExit, [&](){this->close();});

    //back to main menu
    connect(settings_, &Settings::GoToMainMenu, this, [&](){stacked_widget_.setCurrentIndex(0); });
    connect(statistic_, &Statistic::GoToMainMenu, [&](){stacked_widget_.setCurrentIndex(0); });

    //choose game window
    connect(main_menu_, &MainMenu::GoToGameWindow, [&](){stacked_widget_.setCurrentIndex(1); });

    //choose settings menu
    connect(main_menu_, &MainMenu::GoToStatistic, [&](){stacked_widget_.setCurrentIndex(2); });

    //choose settings menu
    connect(main_menu_, &MainMenu::GoToSettings, [&](){stacked_widget_.setCurrentIndex(3); } );

}


MainWindow::~MainWindow()
{
}


