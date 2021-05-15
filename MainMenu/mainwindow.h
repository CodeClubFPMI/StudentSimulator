#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QStackedWidget>
#include <QPushButton>
#include "Game/gamewindow.h"
#include "MainMenu/settings.h"
#include "MainMenu/statistic.h"
#include "MainMenu/mainmenu.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QStackedWidget stacked_widget_;

private:

    GameWindow * game_window_;
    MainMenu * main_menu_;
    Settings * settings_;
    Statistic * statistic_;
};
#endif // MAINWINDOW_H
