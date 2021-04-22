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

}

MainWindow::~MainWindow()
{
}

