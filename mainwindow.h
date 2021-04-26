#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QStackedWidget>
#include <QPushButton>
#include "gamewindow.h"
#include "settings.h"
#include "statistic.h"
#include "mainmenu.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QStackedWidget stacked_widget_;
    GameWindow * game_window_;
    MainMenu * main_menu_;
    Settings * settings_;
    Statistic * statistic_;
};
#endif // MAINWINDOW_H
