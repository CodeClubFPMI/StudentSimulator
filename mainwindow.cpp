#include "mainwindow.h"
#include "settings.h"
//
#include "gamemenu.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent), stacked_widget_(this)

{

    main_menu_ = new MainMenu;
    settings_ = new Settings;
    statistic_ = new Statistic;

    resize(800, 790);

    GameMenu* game = new GameMenu;
    stacked_widget_.addWidget(game);

    stacked_widget_.addWidget(main_menu_);
    //stacked_widget_.setCurrentIndex(2);
    stacked_widget_.addWidget(statistic_);
    stacked_widget_.addWidget(settings_);

    stacked_widget_.setCurrentIndex(0);
    stacked_widget_.show();
    setLayout(stacked_widget_.layout());

    //lambda for close game
    auto close=[&](){
       this->close();
    };

    //lamda for choose main menu
    auto choose_main_menu=[&](){
      stacked_widget_.setCurrentIndex(0);
    };

    //lamda for choose statistic menu
    auto choose_statistic=[&](){
      stacked_widget_.setCurrentIndex(1);
    };


    //lamda for choose settings menu
    auto choose_settings=[&](){
      stacked_widget_.setCurrentIndex(2);
    };

    //closing game
    connect(main_menu_, &MainMenu::GoToExit, close);

    //back to main menu
    connect(settings_, &Settings::GoToMainMenu, choose_main_menu);
    connect(statistic_, &Statistic::GoToMainMenu, choose_main_menu);

    //choose settings menu
    connect(main_menu_, &MainMenu::GoToStatistic, choose_statistic);

    //choose settings menu
    connect(main_menu_, &MainMenu::GoToSettings, choose_settings );


}

MainWindow::~MainWindow()
{
}

