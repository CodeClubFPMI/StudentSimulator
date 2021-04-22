#include "mainwindow.h"
#include "settings.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent), stacked_widget_(this)

{
    main_menu_ = new MainMenu;
    settings_ = new Settings;
    statistic_ = new Statistic;

    resize(800, 790);
    stacked_widget_.addWidget(main_menu_);
    //stacked_widget_.setCurrentIndex(2);
    stacked_widget_.addWidget(statistic_);
    stacked_widget_.addWidget(settings_);
    stacked_widget_.setCurrentIndex(1);
    stacked_widget_.show();
    setLayout(stacked_widget_.layout());

    //lambda for close game
    auto close=[&](){
       this->close();
    };
    //closing game
    connect(main_menu_, &MainMenu::GoToExit, close);

}

MainWindow::~MainWindow()
{
}

