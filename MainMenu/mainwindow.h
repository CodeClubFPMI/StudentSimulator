#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QStackedWidget>
#include <QPalette>
#include <QPushButton>
#include "Game/gamewindow.h"
#include "MainMenu/settings.h"
#include "MainMenu/statistic.h"
#include "MainMenu/mainmenu.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public slots:
    void change_image();

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QStackedWidget stacked_widget_;

private:
    QPixmap bkgnd1;
    QPixmap bkgnd2;
    QPixmap bkgnd3;
    QPixmap bkgnd4;
    QPixmap normal_bkgnd1;
    QPixmap normal_bkgnd2;
    int displayed_image_id_ = 0;
    QPalette p = palette();
    GameWindow * game_window_;
    MainMenu * main_menu_;
    Settings * settings_;
    Statistic * statistic_;

};
#endif // MAINWINDOW_H
