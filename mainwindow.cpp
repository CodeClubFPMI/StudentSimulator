#include "mainwindow.h"
#include "settings.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent), stacked_widget_(this)

{
    main_menu_ = new MainMenu;
    settings_ = new Settings;

    resize(800, 790);
    stacked_widget_.addWidget(main_menu_);
    //stacked_widget_.setCurrentIndex(0);
    stacked_widget_.addWidget(settings_);
    stacked_widget_.setCurrentIndex(1);
    stacked_widget_.show();
    setLayout(stacked_widget_.layout());

<<<<<<< HEAD
=======
    auto close=[&](){
       this->close();
    };
    connect(&main_menu_, &MainMenu::GoToExit, close);
>>>>>>> 02d91531f5b0f6c155d4b61a5dd03ad5d9b54875
}

MainWindow::~MainWindow()
{
}

