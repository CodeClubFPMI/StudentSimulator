#include "mainwindow.h"
#include "settings.h"

#include <QTimer>
#include <QDebug>
#include <QScreen>
#include <QFile>
#include <QDesktopWidget>
#include <QApplication>
#include "Game/foodmenu.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent), stacked_widget_(this)

{
    main_menu_ = new MainMenu;
    settings_ = new Settings;
    statistic_ = new Statistic;

    //get maximum height of window without task bar
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    QDesktopWidget *mydesk = QApplication::desktop();
    int height = 2*mydesk->availableGeometry().height() - screenGeometry.height();
    resize(800, height);

    //set background
    bkgnd1.load(":/images/cat1.jpg");
    bkgnd1 = bkgnd1.scaled(size(), Qt::IgnoreAspectRatio);
    p.setBrush(QPalette::Window, bkgnd1);
    setPalette(p);

    bkgnd2.load(":/images/cat2.jpg");
    bkgnd2 = bkgnd2.scaled(size(), Qt::IgnoreAspectRatio);

    bkgnd3.load(":/images/cat3.jpg");
    bkgnd3 = bkgnd3.scaled(size(), Qt::IgnoreAspectRatio);

    bkgnd4.load(":/images/cat4.jpg");
    bkgnd4 = bkgnd4.scaled(size(), Qt::IgnoreAspectRatio);

    normal_bkgnd1.load(":/images/background1.png");
    normal_bkgnd1 = normal_bkgnd1.scaled(size(), Qt::IgnoreAspectRatio);

    normal_bkgnd2.load(":/images/background.png");
    normal_bkgnd2 = normal_bkgnd2.scaled(size(), Qt::IgnoreAspectRatio);


    QTimer * timer_ = new QTimer;
    timer_->setInterval(250);
    connect(timer_, SIGNAL(timeout()), this, SLOT(change_image()));
    timer_->start();

    stacked_widget_.addWidget(main_menu_);
    //stacked_widget_.setCurrentIndex(2);
    stacked_widget_.addWidget(statistic_);
    stacked_widget_.addWidget(settings_);
    stacked_widget_.show();
    setLayout(stacked_widget_.layout());

    //lamda for choose new game window
    auto choose_new_game=[&](){
      game_window_ = new GameWindow(Game::NEW_GAME, this);
      QFile file(":/Styles/GameMenuStyles.css");
      file.open(QFile::ReadOnly);
      game_window_->setStyleSheet(file.readAll());
      stacked_widget_.addWidget(game_window_);
      stacked_widget_.setCurrentIndex(3);
      setWindowTitle(game_window_->get_student_ptr()->get_name());
      file.close();
    };

    auto choose_load_game=[&](){
        game_window_ = new GameWindow(Game::LOAD_GAME, this);
        QFile file(":/Styles/GameMenuStyles.css");
        file.open(QFile::ReadOnly);
        game_window_->setStyleSheet(file.readAll());
        stacked_widget_.addWidget(game_window_);
        stacked_widget_.setCurrentIndex(3);
        setWindowTitle(game_window_->get_student_ptr()->get_name());
        file.close();
    };

    //closing game
    connect(main_menu_, &MainMenu::GoToExit, [&](){this->close();});

    //back to main menu
    connect(settings_, &Settings::GoToMainMenu, [&](){stacked_widget_.setCurrentIndex(0); });
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

void MainWindow::change_image(){
       if (stacked_widget_.currentIndex() != 3) {
        if (displayed_image_id_ == 0) {
            p.setBrush(QPalette::Window, bkgnd2);
            setPalette(p);
        }
        if (displayed_image_id_ == 1){
            p.setBrush(QPalette::Window, bkgnd3);
            setPalette(p);
        }
        if (displayed_image_id_ == 2){
            p.setBrush(QPalette::Window, bkgnd4);
            setPalette(p);
        }
        if (displayed_image_id_ == 3){
            p.setBrush(QPalette::Window, bkgnd1);
            setPalette(p);
        }
        displayed_image_id_ = (displayed_image_id_ + 1) % 4;
    } else {
        if (displayed_image_id_ % 20 >10) {
           p.setBrush(QPalette::Window, normal_bkgnd1);
           setPalette(p);
        } else {
            p.setBrush(QPalette::Window, normal_bkgnd2);
            setPalette(p);
        }
        displayed_image_id_ = (displayed_image_id_ + 1) % 20;
  }
}
