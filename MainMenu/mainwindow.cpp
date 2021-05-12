#include "mainwindow.h"
#include "settings.h"

#include <QFile>
#include "Game/foodmenu.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent), stacked_widget_(this)

{
    main_menu_ = new MainMenu;
    settings_ = new Settings;
    statistic_ = new Statistic;

    resize(800, 1000);

    stacked_widget_.addWidget(main_menu_);
    //stacked_widget_.setCurrentIndex(2);
    stacked_widget_.addWidget(statistic_);
    stacked_widget_.addWidget(settings_);
    stacked_widget_.show();
    setLayout(stacked_widget_.layout());

    //lamda for choose new game window
    auto choose_new_game=[&](){
      game_window_ = new GameWindow(Game::NEW_GAME);
      QFile file(":/Styles/GameMenuStyles.css");
      file.open(QFile::ReadOnly);
      game_window_->setStyleSheet(file.readAll());
      stacked_widget_.addWidget(game_window_);
      stacked_widget_.setCurrentIndex(3);
      file.close();
    };

    auto choose_load_game=[&](){
        game_window_ = new GameWindow(Game::LOAD_GAME);
        QFile file(":/Styles/GameMenuStyles.css");
        file.open(QFile::ReadOnly);
        game_window_->setStyleSheet(file.readAll());
        stacked_widget_.addWidget(game_window_);
        stacked_widget_.setCurrentIndex(3);
        file.close();
    };

    //closing game
    connect(main_menu_, &MainMenu::GoToExit, [&](){this->close();});

    //back to main menu
    connect(settings_, &Settings::GoToMainMenu, this, [&](){stacked_widget_.setCurrentIndex(0); });
    connect(statistic_, &Statistic::GoToMainMenu, [&](){stacked_widget_.setCurrentIndex(0); });

    //choose new game
    connect(main_menu_, &MainMenu::GoToNewGame, choose_new_game);

    connect(main_menu_, &MainMenu::GoToLoadGame, choose_load_game);


    //choose settings menu
    connect(main_menu_, &MainMenu::GoToStatistic, [&](){stacked_widget_.setCurrentIndex(1); });

    //choose settings menu
    connect(main_menu_, &MainMenu::GoToSettings, [&](){stacked_widget_.setCurrentIndex(2); } );

}


MainWindow::~MainWindow()
{
}


